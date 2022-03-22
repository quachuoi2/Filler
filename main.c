/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:45 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/22 06:49:28 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	store_drawing(t_drawing *drawing, int type)
{
	int	i;
	int	i2;

	i = 0;
	while (!ft_isdigit(drawing->layout[0][i]))
		i++;
	drawing->y = ft_atoi(drawing->layout[0] + i);
	i += 2;
	drawing->x = ft_atoi(drawing->layout[0] + i);
	i = -1;
	i2 = drawing->y + type;
	while (++i < i2)
		get_next_line(0, drawing->layout + i);
}

void	print_map(t_drawing map, int fd, int type)
{
	int	i;

	i = 0;
	while (i < map.y + type)
	{
		write(fd, map.layout[i], map.x + (type * 4));
		write(fd, "\n", 1);
		i++;
	}
}

int	main(void)
{
	char	*index;
	t_drawing	map;
	t_drawing	piece;

	int fd = open("output", O_WRONLY);
	map.layout = (char **)malloc(sizeof(char *)* 16);
	piece.layout = (char **)malloc(sizeof(char *)* 16);
	while (get_next_line(0, map.layout + 0))
	{
		if (map.layout[0][1] == 'l')
		{
			store_drawing(&map, 1);
			print_map(map, fd, 1);
			get_next_line(0, piece.layout + 0);
			store_drawing(&piece, 0);
			print_map(piece, fd, 0);
			ft_printf("8 2\n");
			write(fd, "\n", 1);
		}
	}
/* 	free(map.layout);
	free(piece.layout); */
	return (0);
}
