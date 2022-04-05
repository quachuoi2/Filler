/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 07:52:46 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/05 20:37:12 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_char(char *line, t_players_specs *player)
{
	if (ft_strstr(line, "qnguyen"))
	{
		if (line[10] == '1')
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

void	free_drawing(t_drawing *drawing, int type)
{
	int	i;

	i = 0;
	while (i < drawing->y + type)
	{
		ft_memdel((void **)(drawing->layout + i));
		i++;
	}
	ft_memdel((void **)&drawing->layout);
}

void	assigner(t_search_range *a, t_search_range *b)
{
	a->start = b->start;
	a->increment = b->increment;
	a->end = b->end;
}

int	free_bundle(t_drawing *map, t_drawing *piece, char **line)
{
	//if (map->layout)
		free_drawing(map, 1);
	//if (piece->layout)
		free_drawing(piece, 0);
	//if (*line)
		ft_memdel((void **)line);
	return (0);
}
