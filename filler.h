/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:30:09 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/22 05:19:45 by qnguyen          ###   ########.fr       */
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

#endif