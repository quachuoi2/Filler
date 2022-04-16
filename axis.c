/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:27:58 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 09:09:18 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set_axis_direction(t_search_range *temp_axis)
{
	int	border;

	border = 0;
	if (plyr[0].bound.top_row >= plyr[1].bound.bot_row)
		assigner(temp_axis, 0, 1, map.size.y + 1);
	else
	{
		if ((plyr[0].bound.top_row < plyr[1].bound.top_row) || (plyr[0].bound.bot_row < plyr[1].bound.bot_row))
		{
			assigner(temp_axis, map.size.y, -1, -1);
			border = 0b10;
		}
		else
			assigner(temp_axis, 0, 1, map.size.y + 1);
	}
	if (plyr[0].bound.left_col >= plyr[1].bound.rigt_col)
		assigner(temp_axis + 1, 0, 1, map.size.x + 4);
	else
	{
		if ((plyr[0].bound.left_col < plyr[1].bound.left_col) || (plyr[0].bound.rigt_col < plyr[1].bound.rigt_col))
		{
			assigner(temp_axis + 1, map.size.x + 3, -1, -1);
			border += 0b01;
		}
		else
			assigner(temp_axis + 1, 0, 1, map.size.x + 4);
	}
	return (border);
}

void	set_axis_orientation(t_search_range *temp_axis)
{
	if (piece.leng < piece.width)
	{
		ft_swap(&(temp_axis[0].start), &(temp_axis[1].start));
		ft_swap(&(temp_axis[0].increment), &(temp_axis[1].increment));
		ft_swap(&(temp_axis[0].end), &(temp_axis[1].end));
	}
}
