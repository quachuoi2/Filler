/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:33:37 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 22:00:25 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_map(char *line, int fd, int fd2)
{
	int		i;

	get_size(line, 1);
	map.layout = (char **)ft_memalloc(sizeof(char *) * (map.size.y + 1));
	i = 0;
	while (i < map.size.y + 1)
	{
		get_next_line(fd2, map.layout + i);
		i++;
	}
	check_enemy_border();
	get_players_boundaries();
}

void	read_piece(char *line, int fd, int fd2)
{
	int		i;

	get_size(line, 0);
	piece.layout = (char **)ft_memalloc(sizeof(char *) * (piece.size.y));
	i = 0;
	while (i < piece.size.y)
	{
		get_next_line(fd2, piece.layout + i);
		ft_printf("$0%s\n", fd, piece.layout[i]); //rm
		i++;
	}
	get_piece_boundaries();
	set_length_width();
}
