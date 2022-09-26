/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:45:03 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/21 12:40:18 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_char(char *line)
{
	if (ft_strstr(line, "qnguyen"))
	{
		if (line[10] == '1')
		{
			g_plyr[0].up_c = 'O';
			g_plyr[0].lo_c = 'o';
			g_plyr[1].up_c = 'X';
			g_plyr[1].lo_c = 'x';
		}
		else
		{
			g_plyr[0].up_c = 'X';
			g_plyr[0].lo_c = 'x';
			g_plyr[1].up_c = 'O';
			g_plyr[1].lo_c = 'o';
		}
	}
}

void	get_size(char *line, int type)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	if (type)
		g_map.size.y = ft_atoi(line + i);
	else
		g_piece.size.y = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	if (type)
		g_map.size.x = ft_atoi(line + i + 1);
	else
		g_piece.size.x = ft_atoi(line + i + 1);
}

void	check_boundaries(int i, int i2, t_boundaries *bound)
{
	if (i2 < bound->left)
		bound->left = i2;
	if (i2 > bound->rigt)
		bound->rigt = i2;
	if (bound->top == -1)
		bound->top = i;
	bound->bot = i;
}

void	get_players_boundaries(void)
{
	int		i;
	int		i2;

	g_plyr[0].bnd.left = g_map.size.x + 3;
	g_plyr[0].bnd.rigt = 0;
	g_plyr[0].bnd.top = -1;
	g_plyr[1].bnd.left = g_map.size.x + 3;
	g_plyr[1].bnd.rigt = 0;
	g_plyr[1].bnd.top = -1;
	i = -1;
	while (++i < g_map.size.y + 1)
	{
		i2 = -1;
		while (++i2 < g_map.size.x + 4)
		{
			if (g_map.layout[i][i2] == g_plyr[0].up_c)
				check_boundaries(i, i2, &(g_plyr[0].bnd));
			else if ((g_map.layout[i][i2] == g_plyr[1].up_c)
				|| (g_map.layout[i][i2] == g_plyr[1].lo_c))
				check_boundaries(i, i2, &(g_plyr[1].bnd));
		}
	}
}

void	get_piece_boundaries(void)
{
	int		i;
	int		i2;

	g_piece.bnd.left = g_piece.size.x;
	g_piece.bnd.rigt = 0;
	g_piece.bnd.top = -1;
	i = -1;
	while (++i < g_piece.size.y)
	{
		i2 = -1;
		while (++i2 < g_piece.size.x)
			if (g_piece.layout[i][i2] == '*')
				check_boundaries(i, i2, &(g_piece.bnd));
	}
}
