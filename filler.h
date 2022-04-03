/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/03 18:32:06 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libftprintf.h"
# include "get_next_line.h"

typedef struct s_drawing
{
	int		x;
	int		y;
	char	**layout;
}				t_drawing;

typedef struct	s_players_specs
{
	char	c;
	int		x;
	int		y;
}				t_players_specs;

typedef	struct s_search_range
{
	int	start;
	int	increment;
	int	end;
}				t_search_range;


//algo.c
void	place_token(t_drawing *map, t_drawing *piece, t_players_specs *player);

//utilities.c
void	get_drawing(t_drawing *drawing, char *line, int fd, int type);
void	get_position(t_drawing *map, t_players_specs *player);
void	get_char(char *line, t_players_specs *player);
int		check_condition(int x, int mx, char piece, char map);
#endif