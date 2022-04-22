/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 07:52:46 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/22 11:20:07 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_stuff(void)
{
	int	i;

	i = 0;
	while (i < g_map.size.y + 1)
	{
		ft_memdel((void **)(g_map.layout + i));
		if (i < g_piece.size.y)
			ft_memdel((void **)(g_piece.layout + i));
		i++;
	}
	ft_memdel((void **)&g_map.layout);
	ft_memdel((void **)&g_piece.layout);
}

void	assigner(t_search_range *a, int start, int increment, int end)
{
	a->start = start;
	a->increment = increment;
	a->end = end;
}

void	set_length_width(void)
{
	g_piece.wid = g_piece.bnd.rigt - g_piece.bnd.left + 1;
	g_piece.len = g_piece.bnd.bot - g_piece.bnd.top + 1;
}
