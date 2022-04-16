/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:31:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 19:59:16 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	try_spot(t_coord map_crd)
{
	int		counter;
	t_coord	real_crd;
	t_coord	pie_crd;
	t_coord	potential_crd;

	pie_crd.y = piece.bound.top_row - 1;
	counter = 0;
	while (++pie_crd.y < piece.size.y)
	{
		pie_crd.x = piece.bound.left_col - 1;
		while (++pie_crd.x < piece.size.x)
		{
			if (piece.layout[pie_crd.y][pie_crd.x] == '*')
			{
				real_crd.y = map_crd.y + pie_crd.y - piece.bound.top_row;
				real_crd.x = map_crd.x + pie_crd.x - piece.bound.left_col;
				if (real_crd.y <= map.size.y && real_crd.x <= map.size.x + 3)
				{
					if (map.layout[real_crd.y][real_crd.x] == plyr[0].up_c)
					{
						counter++;
						potential_crd.y = real_crd.y;
						potential_crd.x = real_crd.x;
					}
					else if (map.layout[real_crd.y][real_crd.x] != '.')
						return (0);
				}
				else
					return (0);
			}
		}
	}
	if (counter == 1)
		return (brdr_val(map_crd, potential_crd));
	return (0);
}

void	set_orientation(t_coord *current_crd, t_search_range *axis)
{
	if (piece.leng < piece.width)
	{
		current_crd->x = axis[0].start;
		current_crd->y = axis[1].start;
	}
	else
	{
		current_crd->y = axis[0].start;
		current_crd->x = axis[1].start;
	}
}

void	place_token(t_search_range *temp_axis, t_coord *best_crd, int fd)
{
	int				temp_start;
	int				best_value;
	int				spot_value;
	t_coord			current_crd;

	temp_start = temp_axis[1].start;
	best_value = 0;
	while (temp_axis[0].start != temp_axis[0].end)
	{
		temp_axis[1].start = temp_start;
		while (temp_axis[1].start != temp_axis[1].end)
		{
			set_orientation(&current_crd, temp_axis);
			spot_value = try_spot(current_crd);
			if (spot_value > best_value)
			{
				best_value = spot_value;
				best_crd->y = current_crd.y;
				best_crd->x = current_crd.x;
			}
			temp_axis[1].start += temp_axis[1].increment;
		}
		temp_axis[0].start += temp_axis[0].increment;
	}
	ft_printf("$0value: %d\n%d %d\n", fd, best_value, best_crd->y - piece.bound.top_row - 1, best_crd->x - piece.bound.left_col - 4);
}

void	filler(int fd)
{
	t_search_range	temp_axis[2];
	t_coord			best_crd;

	plyr[0].pref_brdr = set_axis_direction(temp_axis);
	set_axis_orientation(temp_axis);
	ft_printf("$0%d -> %d\n%d -> %d\n",  fd, temp_axis[0].start, temp_axis[0].end, temp_axis[1].start, temp_axis[1].end);
	ft_printf("$0border: %02b\n", fd, plyr[0].pref_brdr);
	ft_printf("$0enemy border: %04b\n", fd, plyr[1].e_brdr);
	best_crd.y = 1;
	best_crd.x = 4;
	place_token(temp_axis, &best_crd, fd);
	ft_printf("%d %d\n", best_crd.y - piece.bound.top_row - 1, best_crd.x - piece.bound.left_col - 4);
}
