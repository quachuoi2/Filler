/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 07:52:46 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/03 18:44:02 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_drawing(t_drawing *drawing, char *line, int fd, int type)
{
	int		i;

	i = 0;
	while(!ft_isdigit(line[i]))
		i++;
	drawing->y = ft_atoi(line + i);
	while(line[i] != ' ')
		i++;
	i++;
	drawing->x = ft_atoi(line + i);
	drawing->layout = (char **)malloc(sizeof(char *) * (drawing->y + type));
	i = 0;
	while (i < drawing->y + type)
	{
		get_next_line(0, drawing->layout + i);
		ft_printf("$0%s\n", fd, drawing->layout[i]);
		i++;
	}
}

void	get_char(char *line, t_players_specs *player)
{
	if (ft_strstr(line, "qnguyen"));
	{
		if (ft_strchr(line, '1'))
		{
			player[0].c = 'O';
			player[1].c = 'X';
		}
		else
		{
			player[0].c = 'X';
			player[1].c = 'O';
		}
	}
}

void	get_position(t_drawing *map, t_players_specs *player)
{
	int		i;
	int		i2;

	i = 0;
	while (i < map->y)
	{
		i2 = 0;
		while (i2 < map->x + 3)
		{
			if (map->layout[i][i2] == player[1].c)
			{
				player[1].y = i;
				player[1].x = i2;
			}
			else if (map->layout[i][i2] == player[0].c)
			{
				player[0].y = i;
				player[0].x = i2;
			}
			i2++;
		}
		i++;
	}
}

int	check_condition(int n, int map_x, char piece, char map)
{
	if (n <= map_x && piece == '*')
	{
		if (map == 'O')
			return (1);
		else if (map != '.')
			return (0);
		return (-1);
	}
	return (-1);
}
