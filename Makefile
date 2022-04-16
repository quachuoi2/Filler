# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 21:27:32 by qnguyen           #+#    #+#              #
#    Updated: 2022/04/15 21:57:17 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = qnguyen.filler
SRC = main.c algo.c utilities.c get.c axis.c border.c reader.c
ANIME = animate.c reader.c utilities.c get.c border.c
all:
	@gcc -g -o3 $(SRC) -L. -lftprintf -I../get_next_line -I../printf_v2 -I../libft -o qnguyen.filler
	@rm game_result
	@rm output
	@touch output
	@resourceslinux/filler_vm -v -f resourceslinux/maps/map00 -p1 ./qnguyen.filler -p2 ./resourceslinux/players/cgamora.filler > game_result

m :
	@gcc -g -O3 $(SRC) -L. -lftprintf -I../get_next_line -I../printf_v2 -I../libft -o qnguyen.filler

p1:
	@resourceslinux/filler_vm -v -f resourceslinux/maps/map00 -p1 ./qnguyen.filler -p2 ./resourceslinux/players/cgamora.filler > game_result

p2:
	@resourceslinux/filler_vm -v -f resourceslinux/maps/map00 -p2 ./qnguyen.filler -p1 ./resourceslinux/players/cgamora.filler > game_result

anime:
	@gcc -g -O3 $(ANIME) -L. -lftprintf -I../get_next_line -I../printf_v2 -I../libft

clean:
	@rm -f qnguyen.filler