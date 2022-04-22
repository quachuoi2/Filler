/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:43:56 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/22 11:11:49 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

t_map			g_map;
t_piece			g_piece;
t_plyrs_specs	g_plyr[2];

void	delay(int number_of_seconds)
{
	int		milli_seconds;
	clock_t	start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}

void	print_map(void)
{
	int	i;
	int	i2;

	i = 0;
	while (i < g_map.size.y + 1)
	{
		if (ft_strchr(g_map.layout[i], g_plyr[0].lo_c)
			|| ft_strchr(g_map.layout[i], g_plyr[1].lo_c))
		{
			i2 = 0;
			while (g_map.layout[i][i2] != '\0')
			{
				if (g_map.layout[i][i2] == g_plyr[0].lo_c)
					ft_printf("$b");
				else if (g_map.layout[i][i2] == g_plyr[1].lo_c)
					ft_printf("$r");
				ft_printf("%c$d", g_map.layout[i][i2]);
				i2++;
			}
		}
		else
			ft_printf("%s", g_map.layout[i]);
		ft_printf("\n");
		i++;
	}
}

void	score(void)
{
	int	i;
	int	i2;
	int	p1;
	int	p2;

	p1 = 0;
	p2 = 0;
	i = 0;
	while (i < g_map.size.y + 1)
	{
		i2 = 0;
		while (i2 < g_map.size.x + 4)
		{
			if (g_map.layout[i][i2] == g_plyr[0].lo_c
				|| g_map.layout[i][i2] == g_plyr[0].up_c)
				p1++;
			else if (g_map.layout[i][i2] == g_plyr[1].lo_c
				|| g_map.layout[i][i2] == g_plyr[1].up_c)
				p2++;
			i2++;
		}
		i++;
	}
	ft_printf("$bp1$d %d - %d $rp2$d\n", p1, p2);
}

void	read_map_fd(char *line, int fd)
{
	int		i;

	get_size(line, 1);
	g_map.layout = (char **)ft_memalloc(sizeof(char *) * (g_map.size.y + 1));
	i = 0;
	while (i < g_map.size.y + 1)
	{
		get_next_line(fd, g_map.layout + i);
		i++;
	}
	check_enemy_border();
	get_players_boundaries();
}

int	main(void)
{
	char			*line;
	int				fd;
	int				i;

	fd = open("game_result", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[1] == 'l')
		{
			ft_printf("\e[1;1H\e[2J");
			read_map_fd(line, fd);
			print_map();
			score();
			i = -1;
			while (++i < g_map.size.y + 1)
				ft_memdel((void **)(g_map.layout + i));
			delay(500);
		}
		else if (line[0] == '$')
			get_char(line);
		ft_memdel((void **)&line);
	}
	return (0);
}
