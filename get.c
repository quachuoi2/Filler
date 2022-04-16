/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:45:03 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 20:00:02 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_char(char *line)
{
	if (ft_strstr(line, "qnguyen"))
	{
		if (line[10] == '1')
		{
			plyr[0].up_c = 'O';
			plyr[0].lo_c = 'o';
			plyr[1].up_c = 'X';
			plyr[1].lo_c = 'x';
		}
		else
		{
			plyr[0].up_c = 'X';
			plyr[0].lo_c = 'x';
			plyr[1].up_c = 'O';
			plyr[1].lo_c = 'o';
		}
	}
}

void	get_size(char *line, int type)
{
	int i;

	i = 0;
	while(!ft_isdigit(line[i]))
		i++;
	if (type)
		map.size.y = ft_atoi(line + i);
	else
		piece.size.y = ft_atoi(line + i);
	while(line[i] != ' ')
		i++;
	if (type)
		map.size.x = ft_atoi(line + i + 1);
	else
		piece.size.x = ft_atoi(line + i + 1);
}

void	check_boundaries(int i, int i2, t_boundaries *bound)
{
	if (i2 < bound->left_col)
		bound->left_col = i2;
	if (i2 > bound->rigt_col)
		bound->rigt_col = i2;
	if (bound->top_row == -1)
		bound->top_row = i;
	bound->bot_row = i;
}

void	get_players_boundaries(void)
{
	int		i;
	int		i2;

	plyr[0].bound.left_col = map.size.x + 3;
	plyr[0].bound.rigt_col = 0;
	plyr[0].bound.top_row = -1;
	plyr[1].bound.left_col = map.size.x + 3;
	plyr[1].bound.rigt_col = 0;
	plyr[1].bound.top_row = -1;
	i = -1;
	while (++i < map.size.y + 1)
	{
		i2 = -1;
		while (++i2 < map.size.x + 4)
		{
			if (map.layout[i][i2] == plyr[0].up_c)
				check_boundaries(i, i2, &(plyr[0].bound));
			else if ((map.layout[i][i2] == plyr[1].up_c)
				|| (map.layout[i][i2] == plyr[1].lo_c))
				check_boundaries(i, i2, &(plyr[1].bound));
		}
	}
}

void	get_piece_boundaries(void)
{
	int		i;
	int		i2;

	piece.bound.left_col = piece.size.x;
	piece.bound.rigt_col = 0;
	piece.bound.top_row = -1;
	i = -1;
	while (++i < piece.size.y)
	{
		i2 = -1;
		while (++i2 < piece.size.x)
			if (piece.layout[i][i2] == '*')
				check_boundaries(i, i2, &(piece.bound));
	}
}
