/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:45 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/05 20:57:00 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	get_drawing(t_drawing *drawing, char *line, int type, int fd, int fd2)
{
	int		i;
	static int z;

	i = 0;
	while(!ft_isdigit(line[i]))
		i++;
	drawing->y = ft_atoi(line + i);
	while(line[i] != ' ')
		i++;
	drawing->x = ft_atoi(line + i + 1);
	if (drawing->layout)
		free_drawing(drawing, type);
	drawing->layout = (char **)ft_memalloc(sizeof(char *) * (drawing->y + type));
	i = 0;
	while (i < drawing->y + type)
	{
		get_next_line(fd2, drawing->layout + i);
		ft_printf("$0%s\n", fd, drawing->layout[i]);
		i++;
	}
}

int	main(void)
{
	char			*line;
	t_drawing		map;
	t_drawing		piece;
	t_players_specs player[2];
	int 			fd;
	int 			fd2;

	fd = open("output", O_WRONLY);
	fd2 = open("z", O_RDONLY);
	map.layout = NULL;
	piece.layout = NULL;
	while (get_next_line(fd2, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			get_drawing(&map, line, 1, fd, fd2);
			get_position(&map, player);
		}
		else if (ft_strstr(line, "Piece"))
		{
			get_drawing(&piece, line, 0, fd, fd2);
/* 			if (!place_token(&map, &piece, player, fd))
				break; */
		}
		else if (line[0] == '$')
			get_char(line, player);
		ft_memdel((void **)&line);
	}
	free_bundle(&map, &piece, &line);
	return (0);
}
