/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:45 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/04 18:39:44 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	get_drawing(t_drawing *drawing, char *line, int type)
{
	int		i;

	i = 0;
	while(!ft_isdigit(line[i]))
		i++;
	drawing->y = ft_atoi(line + i);
	while(line[i] != ' ')
		i++;
	drawing->x = ft_atoi(line + i + 1);
	if (drawing->layout)
		free_bundle(drawing, type);
	drawing->layout = (char **)malloc(sizeof(char *) * (drawing->y + type));
	i = 0;
	while (i < drawing->y + type)
	{
		get_next_line(0, drawing->layout + i);
		i++;
	}
}

void	print_thing(t_drawing *drawing, int fd, int type)
{
	int i = 0;

	while (i < drawing->y + type)
	{
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

	fd = open("output", O_WRONLY);
	map.layout = NULL;
	piece.layout = NULL;
	while (get_next_line(0, &line))
	{
		if (line[1] == 'l')
		{
			get_drawing(&map, line, 1);
			get_position(&map, player);
			print_thing(&map, fd, 1);
		}
		else if (line[1] == 'i')
		{
			get_drawing(&piece, line, 0);
			print_thing(&piece, fd, 0);
			if (!place_token(&map, &piece, player, fd))
			{
				free_bundle(&map, 1);
				free_bundle(&piece, 0);
				break;
			}
		}
		else if (line[0] == '$')
			get_char(line, player);
		else if (line[0] == '@')
			break;
		if (line)
			ft_memdel((void **)&line);
	}
	return (0);
}
