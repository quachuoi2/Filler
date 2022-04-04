/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/04 18:21:50 by qnguyen          ###   ########.fr       */
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
int		place_token(t_drawing *map, t_drawing *piece, t_players_specs *player, int fd);

//utilities.c
void	get_position(t_drawing *map, t_players_specs *player);
void	get_char(char *line, t_players_specs *player);
int		check_condition(int x, int mx, char piece, char map);
void	free_bundle(t_drawing *drawing, int type);
void	assigner(t_search_range *a, t_search_range *b);

#endif