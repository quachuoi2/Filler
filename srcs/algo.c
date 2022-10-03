/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:31:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/10/03 19:56:24 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_char(t_coord *poss_crd, t_coord *real_crd, int *counter)
{
	if (g_map.layout[real_crd->y][real_crd->x] == g_plyr[0].up_c)
	{
		poss_crd->y = real_crd->y;
		poss_crd->x = real_crd->x;
		(*counter)++;
		return (1);
	}
	else if (g_map.layout[real_crd->y][real_crd->x] != '.')
		return (0);
	return (-1);
}

int	try_spot(t_coord map_crd)
{
	int		counter;
	t_coord	real_crd;
	t_coord	pie_crd;
	t_coord	poss_crd;

	pie_crd.y = g_piece.bnd.top - 1;
	counter = 0;
	while (++pie_crd.y < g_piece.size.y)
	{
		pie_crd.x = g_piece.bnd.left - 1;
		while (++pie_crd.x < g_piece.size.x)
		{
			if (g_piece.layout[pie_crd.y][pie_crd.x] == '*')
			{
				real_crd.y = map_crd.y + pie_crd.y - g_piece.bnd.top;
				real_crd.x = map_crd.x + pie_crd.x - g_piece.bnd.left;
				if (real_crd.y > g_map.size.y || real_crd.x > g_map.size.x + 3
					|| !check_char(&poss_crd, &real_crd, &counter))
					return (0);
			}
		}
	}
	return (brdr_val(map_crd, poss_crd, counter));
}

void	set_orientation(t_coord *current_crd, t_search_range *axis)
{
	if (g_piece.len < g_piece.wid)
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

void	place_token(t_search_range *temp_axis, t_coord *best_crd)
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
}

void	filler(void)
{
	t_search_range	temp_axis[2];
	t_coord			best_crd;

	g_plyr[0].pref_brdr = set_y_axis_direction(temp_axis);
	g_plyr[0].pref_brdr += set_x_axis_direction(temp_axis);
	set_axis_orientation(temp_axis);
	best_crd.y = 1;
	best_crd.x = 4;
	place_token(temp_axis, &best_crd);
	ft_printf("%d %d\n", best_crd.y - g_piece.bnd.top - 1,
		best_crd.x - g_piece.bnd.left - 4);
}
