/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:20:36 by qnguyen           #+#    #+#             */
/*   Updated: 2022/09/26 07:40:46 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_enemy_border(void)
{
	t_coord	crd;

	crd.y = -1;
	g_plyr[1].e_brdr = 0;
	while (++crd.y < g_map.size.y + 1)
	{
		crd.x = -1;
		while (++crd.x < g_map.size.x + 4)
		{
			if ((g_map.layout[crd.y][crd.x] == g_plyr[1].up_c)
				|| (g_map.layout[crd.y][crd.x] == g_plyr[1].lo_c))
			{
				if (!(g_plyr[1].e_brdr & 0b1000))
					g_plyr[1].e_brdr |= (vertcl_brdr(crd, 0, 1) << 3);
				if (!(g_plyr[1].e_brdr & 0b0100))
					g_plyr[1].e_brdr |= (vertcl_brdr(crd, 1, 1) << 2);
				if (!(g_plyr[1].e_brdr & 0b0010))
					g_plyr[1].e_brdr |= (horzntl_brdr(crd, 0, 1) << 1);
				if (!(g_plyr[1].e_brdr & 0b0001))
					g_plyr[1].e_brdr |= horzntl_brdr(crd, 1, 1);
			}
		}
	}
}

int	vertcl_brdr(t_coord crd, int type, int p_type)
{
	int	i;
	int	first;
	int	last;

	first = -1;
	last = -1;
	i = 0;
	while (i < g_map.size.y + 1)
	{
		if ((!p_type && g_map.layout[i][crd.x] == g_plyr[0].up_c)
			|| (p_type && ft_isalpha(g_map.layout[i][crd.x])))
		{
			if (first == -1)
				first = i;
			last = i;
		}
		i++;
	}
	if ((type && crd.y == last && crd.y != g_map.size.y)
		|| (!type && crd.y == first && crd.y != 0))
		return (1);
	return (0);
}

int	horzntl_brdr(t_coord crd, int type, int p_type)
{
	int	i;
	int	first;
	int	last;

	first = -1;
	last = -1;
	i = 0;
	while (i < g_map.size.x + 4)
	{
		if ((!p_type && g_map.layout[crd.y][i] == g_plyr[0].up_c)
			|| (p_type && ft_isalpha(g_map.layout[crd.y][i])))
		{
			if (first == -1)
				first = i;
			last = i;
		}
		i++;
	}
	if ((type && crd.x == last && crd.x != g_map.size.x + 3)
		|| (!type && crd.x == first && crd.x != 0))
		return (1);
	return (0);
}

int	brdr_counter(int brdr)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (i < 4)
	{
		if (brdr & (1 << i))
			counter++;
		i++;
	}
	return (counter);
}

//?????
int	brdr_val(t_coord map_crd, t_coord crd, int counter)
{
	int		val;
	int		bor_nb;
	int		i;
	t_coord	c;

	if (counter != 1)
		return (0);
	val = 1;
	c.y = crd.y - map_crd.y + g_piece.bnd.top;
	c.x = crd.x - map_crd.x + g_piece.bnd.left;
	bor_nb = (brdr_counter(g_plyr[1].e_brdr) < 3);
	i = vertcl_brdr(crd, 0, 0);
	val += i * (i + ((g_plyr[0].pref_brdr & 2) == 0) + ((g_plyr[1].e_brdr & 8)
				!= 0) * bor_nb - (c.y == g_piece.bnd.top) * (g_piece.len > 1));
	i = vertcl_brdr(crd, 1, 0);
	val += i * (i + ((g_plyr[0].pref_brdr & 2) != 0) + ((g_plyr[1].e_brdr & 4)
				!= 0) * bor_nb - (c.y == g_piece.bnd.bot) * (g_piece.len > 1));
	i = horzntl_brdr(crd, 0, 0);
	val += i * (i + ((g_plyr[0].pref_brdr & 1) == 0) + ((g_plyr[1].e_brdr & 2)
				!= 0) * bor_nb - (c.x == g_piece.bnd.left) * (g_piece.wid > 1));
	i = horzntl_brdr(crd, 1, 0);
	val += i * (i + ((g_plyr[0].pref_brdr & 1) != 0) + ((g_plyr[1].e_brdr & 1)
				!= 0) * bor_nb - (c.x == g_piece.bnd.rigt) * (g_piece.wid > 1));
	return (val);
}
