/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:20:36 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 20:55:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_enemy_border(void)
{
	t_coord	crd;

	crd.y = -1;
	plyr[1].e_brdr = 0;
	while (++crd.y < map.size.y + 1)
	{
		crd.x = -1;
		while (++crd.x < map.size.x + 4)
		{
			if ((map.layout[crd.y][crd.x] == plyr[1].up_c)
				|| (map.layout[crd.y][crd.x] == plyr[1].lo_c))
				{
					if (!(plyr[1].e_brdr & 0b1000))
						plyr[1].e_brdr
							|= (vertcl_brdr(crd, 0, 1) << 3);
					if (!(plyr[1].e_brdr & 0b0100))
						plyr[1].e_brdr
							|= (vertcl_brdr(crd, 1, 1) << 2);
					if (!(plyr[1].e_brdr & 0b0010))
						plyr[1].e_brdr
							|= (horzntl_brdr(crd, 0, 1) << 1);
					if (!(plyr[1].e_brdr & 0b0001))
						plyr[1].e_brdr
							|= horzntl_brdr(crd, 1, 1);
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
	while (i < map.size.y + 1)
	{
		if ((!p_type && map.layout[i][crd.x] == plyr[0].up_c)
			|| (p_type && ft_isalpha(map.layout[i][crd.x])))
			{
				if (first == -1)
					first = i;
				last = i;
			}
		i++;
	}
	if ((type && crd.y == last && crd.y != map.size.y)
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
	while (i < map.size.x + 4)
	{
		if ((!p_type && map.layout[crd.y][i] == plyr[0].up_c)
			|| (p_type && ft_isalpha(map.layout[crd.y][i])))
		{
			if (first == -1)
				first = i;
			last = i;
		}
		i++;
	}
	if ((type && crd.x == last && crd.x != map.size.x + 3)
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

int	brdr_val(t_coord map_crd, t_coord crd)
{
	int		val;
	int		bor_nb;
	int		i;
	t_coord c;

	val = 1;
	c.y = crd.y - map_crd.y + piece.bound.top_row;
	c.x = crd.x - map_crd.x + piece.bound.left_col;
	bor_nb = (brdr_counter(plyr[1].e_brdr) < 3);
/* 	if (crd.y == 1 + 1 && crd.x == 13 + 4)
	{
		do_thing();
		ft_printf("c.y: %d c.x: %d\n", c.y, c.x);
		ft_printf("t: %d b: %d l: %d r: %d\n", piece.bound.top_row, piece.bound.bot_row, piece.bound.left_col, piece.bound.rigt_col);
		ft_printf("%d %d\n", piece.leng, piece.width);
	} */

	i = vertcl_brdr(crd, 0, 0) ;
	val += i * (i + ((plyr[0].pref_brdr & 2) == 0) + ((plyr[1].e_brdr & 8) != 0) * bor_nb - (c.y == piece.bound.top_row) * (piece.leng > 1)/*  * ((plyr[1].e_brdr & 4) == 0)  */);

	i = vertcl_brdr(crd, 1, 0);
	val += i * (i + ((plyr[0].pref_brdr & 2) != 0) + ((plyr[1].e_brdr & 4) != 0) * bor_nb - (c.y == piece.bound.bot_row) * (piece.leng > 1)/*  * ((plyr[1].e_brdr & 8) == 0)  */);

	i = horzntl_brdr(crd, 0, 0);
	val += i * (i + ((plyr[0].pref_brdr & 1) == 0) + ((plyr[1].e_brdr & 2) != 0) * bor_nb - (c.x == piece.bound.left_col) * (piece.width > 1)/*  * ((plyr[1].e_brdr & 1) == 0)  */);

	i = horzntl_brdr(crd, 1, 0);
	val += i * (i + ((plyr[0].pref_brdr & 1) != 0) + ((plyr[1].e_brdr & 1) != 0) * bor_nb - (c.x == piece.bound.rigt_col) * (piece.width > 1));

	return (val);
}
