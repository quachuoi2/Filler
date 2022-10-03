/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:01:36 by qnguyen           #+#    #+#             */
/*   Updated: 2022/10/03 21:48:40 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "anime.h"
#include <time.h>

void	anime_get_char(char *line)
{
	if (ft_strstr(line, "qnguyen"))
	{
		if (line[10] == '1')
		{
			g_a_plyr[0].up_c = 'O';
			g_a_plyr[0].lo_c = 'o';
			g_a_plyr[1].up_c = 'X';
			g_a_plyr[1].lo_c = 'x';
		}
		else
		{
			g_a_plyr[0].up_c = 'X';
			g_a_plyr[0].lo_c = 'x';
			g_a_plyr[1].up_c = 'O';
			g_a_plyr[1].lo_c = 'o';
		}
		ft_strcpy(g_a_plyr[0].name, "quang");
		ft_strcpy(g_a_plyr[1].name, "opponent :D");
	}
}

void	get_size(char *line, int type)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	if (type)
		g_map.size.y = ft_atoi(line + i);
	else
		g_piece.size.y = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	if (type)
		g_map.size.x = ft_atoi(line + i + 1);
	else
		g_piece.size.x = ft_atoi(line + i + 1);
}

void	delay(int number_of_seconds)
{
	int		milli_seconds;
	clock_t	start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
}
