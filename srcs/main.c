/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:45:45 by qnguyen           #+#    #+#             */
/*   Updated: 2022/10/03 19:55:50 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_map			g_map;
t_piece			g_piece;
t_plyrs_specs	g_plyr[2];

int	main(void)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (line[1] == 'l')
			read_map(line);
		else if (line[1] == 'i')
		{
			read_piece(line);
			filler();
			free_stuff();
		}
		else if (line[0] == '$')
			get_char(line);
		ft_memdel((void **)&line);
	}
	return (0);
}
