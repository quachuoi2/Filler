/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:45 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/03 19:42:18 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char			*line;
	t_drawing		map;
	t_drawing		piece;
	t_players_specs player[2];
	int 			fd;

	fd = open("output", O_WRONLY);
	player[1].x = -1;
	while (get_next_line(0, &line))
	{
		if (line[0] == '$')
			get_char(line, player);
		else if (line[1] == 'l')
		{
			get_drawing(&map, line, fd, 1);
			get_position(&map, player);
		}
		else if (line[1] == 'i')
		{
			get_drawing(&piece, line, fd, 0);
			place_token(&map, &piece, player);
		}
		free(line);
	}
	return (0);
}
