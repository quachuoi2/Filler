/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:31:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/03 18:58:57 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	try_spot(t_drawing *map, t_drawing *piece, int y, int x)
{
	int	i;
	int	i2;
	int	counter;
	int	temp;

	i = -1;
	counter = 0;
	while (++i < piece->y)
	{
		i2 = -1;
		if (y + i <= map->y)
		{
			while (++i2 < piece->x)
			{
				temp = check_condition(x + i2, map->x + 3,
						piece->layout[i][i2], map->layout[y + i][x + i2]);
				if (temp == 1)
					counter++;
				else if (!temp)
					return (0);
			}
		}
	}
	return (counter == 1);
}

void	set_searching_parameter(int me, int enemy, t_search_range *r, int map)
{
	if (me < enemy)
	{
		r->start = map;
		r->end = 0;
		r->increment = -1;
	}
	else
	{
		r->start = 0;
		r->end = map;
		r->increment = 1;
	}
}

int	get_piece_length_width(t_drawing *piece)
{
	int	i;
	int	i2;
	int	width;
	int	max_width;
	int	max_length;

	i = -1;
	max_width = 0;
	max_length = 0;
	while (++i < piece->y)
	{
		width = 0;
		i2 = -1;
		while (++i2 < piece->x)
		{
			if (piece->layout[i][i2] == '*')
				width++;
		}
		max_width = ft_greaternum(max_width, width);
		if (width)
			max_length++;
	}
	return (max_width > max_length);
}

void	place_token(t_drawing *map, t_drawing *piece, t_players_specs *player)
{
	t_search_range	y;
	t_search_range	x;
	int				temp;
	int				search_type;

	set_searching_parameter(player[0].y, player[1].y, &y, map->y);
	set_searching_parameter(player[0].x, player[1].x, &x, map->x + 3);
	search_type = get_piece_length_width(piece);
	temp = x.start;
	while (y.start != y.end)
	{
		x.start = temp;
		while (x.start != x.end)
		{
			if (try_spot(map, piece, y.start, x.start))
			{
				ft_printf("%d %d\n", y.start - 1, x.start - 4);
				return ;
			}
			x.start += x.increment;
		}
		y.start += y.increment;
	}
}

//if token's width is larger than length, try vertically before horizontally
//vice versa

//if enemy is below, try from bottom to top
//vice versa

//if enemy is on the right, check from right to left
//vice versa.