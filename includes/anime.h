/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:02:51 by qnguyen           #+#    #+#             */
/*   Updated: 2022/10/03 21:29:27 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIME_H
# define ANIME_H
# include "filler.h"

typedef struct s_anime_plyrs_specs
{
	char			up_c;
	char			lo_c;
	char			name[100];
}				t_anime_plyrs_specs;

extern t_anime_plyrs_specs	g_a_plyr[2];

void	anime_get_char(char *line);
void	delay(int number_of_seconds);
void	get_size(char *line, int type);

#endif