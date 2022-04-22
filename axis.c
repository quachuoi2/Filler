/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:27:58 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/21 12:40:52 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set_axis_direction(t_search_range *temp_axis)
{
	int	border;

	border = 0;
	if (g_plyr[0].bnd.top >= g_plyr[1].bnd.bot)
		assigner(temp_axis, 0, 1, g_map.size.y + 1);
	else
	{
		if ((g_plyr[0].bnd.top < g_plyr[1].bnd.top)
			|| (g_plyr[0].bnd.bot < g_plyr[1].bnd.bot))
		{
			assigner(temp_axis, g_map.size.y, -1, -1);
			border = 0b10;
		}
		else
			assigner(temp_axis, 0, 1, g_map.size.y + 1);
	}
	if (g_plyr[0].bnd.left >= g_plyr[1].bnd.rigt)
		assigner(temp_axis + 1, 0, 1, g_map.size.x + 4);
	else
	{
		if ((g_plyr[0].bnd.left < g_plyr[1].bnd.left)
			|| (g_plyr[0].bnd.rigt < g_plyr[1].bnd.rigt))
		{
			assigner(temp_axis + 1, g_map.size.x + 3, -1, -1);
			border += 0b01;
		}
		else
			assigner(temp_axis + 1, 0, 1, g_map.size.x + 4);
	}
	return (border);
}

void	set_axis_orientation(t_search_range *temp_axis)
{
	if (g_piece.len < g_piece.wid)
	{
		ft_swap(&(temp_axis[0].start), &(temp_axis[1].start));
		ft_swap(&(temp_axis[0].increment), &(temp_axis[1].increment));
		ft_swap(&(temp_axis[0].end), &(temp_axis[1].end));
	}
}
