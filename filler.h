/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/15 20:03:48 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libftprintf.h"
# include "get_next_line.h"

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_boundaries
{
	int	bot_row;
	int	top_row;
	int	left_col;
	int	rigt_col;
}				t_boundaries;

typedef struct s_map
{
	char	**layout;
	t_coord	size;
}				t_map;

typedef struct s_piece
{
	int				leng;
	int				width;
	char			**layout;
	t_coord			size;
	t_boundaries	bound;
}				t_piece;

typedef struct	s_plyrs_specs
{
	char			up_c;
	char			lo_c;
	unsigned int	pref_brdr : 2;
	unsigned int	e_brdr : 4;
	t_boundaries	bound;
}				t_plyrs_specs;

typedef	struct s_search_range
{
	int	start;
	int	increment;
	int	end;
}				t_search_range;

extern t_map			map;
extern t_piece			piece;
extern t_plyrs_specs	plyr[2];

//algo.c
void	filler(int fd);

//utilities.c
int		check_condition(int x, int mx, char piece, char map);
void	assigner(t_search_range *a, int start, int increment, int end);
void	free_stuff(void);
void	set_length_width();

//get.c
void	get_char(char *line);
void	get_size(char *line, int type);
void	check_boundaries(int i, int i2, t_boundaries *bound);
void	get_players_boundaries(void);
void	get_piece_boundaries(void);

//border.c
void	check_enemy_border();
int		horzntl_brdr(t_coord crd, int type, int p_type);
int		vertcl_brdr(t_coord crd, int type, int p_type);
int		brdr_val(t_coord map_crd, t_coord crd);
int		brdr_counter(int brdr);

//axis.c
int		set_axis_direction(t_search_range *temp_axis);
void	set_axis_orientation(t_search_range *temp_axis);

//main.c
void	do_thing();

//reader.c
void	read_map(char *line, int fd, int fd2);
void	read_piece(char *line, int fd, int fd2);

#endif