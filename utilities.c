/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 07:52:46 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/13 01:51:45 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_stuff(void)
{
	int	i;

	i = 0;
	while (i < map.size.y + 1)
	{
		ft_memdel((void **)(map.layout + i));
		if (i < piece.size.y)
			ft_memdel((void **)(piece.layout + i));
		i++;
	}
	ft_memdel((void **)&map.layout);
	ft_memdel((void **)&piece.layout);
}

void	assigner(t_search_range *a, int start, int increment, int end)
{
	a->start = start;
	a->increment = increment;
	a->end = end;
}

void	set_length_width(void)
{
	piece.width = piece.bound.rigt_col - piece.bound.left_col + 1;
	piece.leng = piece.bound.bot_row - piece.bound.top_row + 1;
}