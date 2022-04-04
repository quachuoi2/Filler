/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:31:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/04 17:10:00 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	try_spot(t_drawing *map, t_drawing *piece, t_search_range *axis, char p_c)
{
	int	i;
	int	i2;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < piece->y)
	{
		i2 = -1;
		while (++i2 < piece->x)
		{
			if (axis[0].start + i <= map->y && axis[1].start + i2 <= map->x + 3)
			{
				if (piece->layout[i][i2] == '*')
				{
					if (map->layout[axis[0].start + i][axis[1].start + i2] == p_c)
						counter++;
					else if (map->layout[axis[0].start + i][axis[1].start + i2] != '.')
						return (0);
				}
			}
			else if (piece->layout[i][i2] == '*')
				return (0);
		}
	}
	return (counter == 1);
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
			if (piece->layout[i][i2] == '*')
				width++;
		max_width = ft_greaternum(max_width, width);
		if (width)
			max_length++;
	}
	return (max_length > max_width);
}

void	set_axis_direction(int me, int enemy, t_search_range *r, int map)
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

void	set_axis_paramenter(t_drawing *piece, t_search_range *y, t_search_range *x, t_search_range *axis)
{
	if (get_piece_length_width(piece))
	{
		assigner(axis + 0, y);
		assigner(axis + 1, x);
	}
	else
	{
		assigner(axis + 0, x);
		assigner(axis + 1, y);
	}
}

int	place_token(t_drawing *map, t_drawing *piece, t_players_specs *player, int fd)
{
	t_search_range	y;
	t_search_range	x;
	t_search_range	axis[2];
	int				temp_start;

	set_axis_direction(player[0].y, player[1].y, &y, map->y);
	set_axis_direction(player[0].x, player[1].x, &x, map->x + 3);
	set_axis_paramenter(piece, &y, &x, axis);
	temp_start = axis[1].start;
	while (axis[0].start != axis[0].end)
	{
		axis[1].start = temp_start;
		while (axis[1].start != axis[1].end)
		{
			if (try_spot(map, piece, axis, player[0].c))
			{
				ft_printf("%d %d\n", axis[0].start - 1, axis[1].start - 4);
				return (1);
			}
			axis[1].start += axis[1].increment;
		}
		axis[0].start += axis[0].increment;
	}
	return (0);
}

//if token's width is larger than length, try vertically before horizontally
//vice versa

//if enemy is below, try from bottom to top
//vice versa

//if enemy is on the right, check from right to left
//vice versa.