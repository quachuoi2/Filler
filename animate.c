/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:43:56 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 22:23:30 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

t_map			map;
t_piece			piece;
t_plyrs_specs	plyr[2];

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void	print_map()
{
	int	i;
	int	i2;

	i = 0;
	while (i < map.size.y + 1)
	{
		if (ft_strchr(map.layout[i], plyr[0].lo_c) || ft_strchr(map.layout[i], plyr[1].lo_c))
		{
			i2 = 0;
			while (map.layout[i][i2] != '\0')
			{
				if (map.layout[i][i2] == plyr[0].lo_c)
					ft_printf("%$bc", plyr[0].lo_c);
				else if (map.layout[i][i2] == plyr[1].lo_c)
					ft_printf("%$rc", plyr[1].lo_c);
				else
					ft_printf("%c");
				i2++;
			}
		}
		else
			ft_printf("%s", map.layout[i]);
		ft_printf("\n");
		i++;
	}
}

void	score()
{
	int	i;
	int	i2;
	int	p1;
	int	p2;

	p1 = 0;
	p2 = 0;
	i = 0;
	while (i < map.size.y + 1)
	{
		i2 = 0;
		while (i2 < map.size.x + 4)
		{
			if (map.layout[i][i2] == plyr[0].lo_c || map.layout[i][i2] == plyr[0].up_c)
				p1++;
			else if (map.layout[i][i2] == plyr[1].lo_c || map.layout[i][i2] == plyr[1].up_c)
				p2++;
			i2++;
		}
		i++;
	}
	ft_printf("$bp1$d %d - %d $rp2$d\n", p1, p2);
}

int	main(void)
{
	char			*line;
	int 			fd;
	int 			fd2;
	int				i;

	fd = open("output", O_WRONLY);
	fd2 = open("game_result", O_RDONLY);
	while (get_next_line(fd2, &line))
	{
		if (line[1] == 'l')
		{
			ft_printf("\e[1;1H\e[2J");
			read_map(line, fd, fd2);
			print_map();
			score();
			i = 0;
			while (i < map.size.y + 1)
			{
				ft_memdel((void **)(map.layout + i));
				i++;
			}
			delay(500);
		}
		else if (line[0] == '$')
			get_char(line);
		ft_memdel((void **)&line);
	}
	return (0);
}