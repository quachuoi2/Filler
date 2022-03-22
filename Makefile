# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 21:27:32 by qnguyen           #+#    #+#              #
#    Updated: 2022/03/22 02:10:50 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = qnguyen.filler
SRC = main.c

all:
	@gcc $(SRC) -L. -lftprintf -I../get_next_line -I../printf -I../libft -o qnguyen.filler
	@resourceslinux/filler_vm -v -f resourceslinux/maps/map00 -p1 ./qnguyen.filler
clean:
	@rm -f qnguyen.filler