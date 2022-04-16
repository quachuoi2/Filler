/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:45 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 20:55:51 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_map			map;
t_piece			piece;
t_plyrs_specs	plyr[2];

void	do_thing()
{
}

int	main(void)
{
	char			*line;
	int 			fd;
	int 			fd2;

	fd = open("output", O_WRONLY);
	fd2 = open("z2", O_RDONLY);
	fd2 = 0;
	while (get_next_line(fd2, &line))
	{
		if (line[1] == 'l')
			read_map(line, fd, fd2);
		else if (line[1] == 'i')
		{
			read_piece(line, fd, fd2);
			filler(fd);
			free_stuff();
		}
		else if (line[0] == '$')
			get_char(line);
		ft_memdel((void **)&line);
	}
	return (0);
}
