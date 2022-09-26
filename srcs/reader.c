/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:33:37 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/21 09:56:14 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(char *line)
{
	int		i;

	get_size(line, 1);
	g_map.layout = (char **)ft_memalloc(sizeof(char *) * (g_map.size.y + 1));
	i = 0;
	while (i < g_map.size.y + 1)
	{
		get_next_line(0, g_map.layout + i);
		i++;
	}
	check_enemy_border();
	get_players_boundaries();
}

void	read_piece(char *line)
{
	int		i;

	get_size(line, 0);
	g_piece.layout = (char **)ft_memalloc(sizeof(char *) * (g_piece.size.y));
	i = 0;
	while (i < g_piece.size.y)
	{
		get_next_line(0, g_piece.layout + i);
		i++;
	}
	get_piece_boundaries();
	set_length_width();
}
