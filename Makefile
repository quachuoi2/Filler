# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 21:27:32 by qnguyen           #+#    #+#              #
#    Updated: 2022/04/04 18:30:31 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = qnguyen.filler
SRC = main.c algo.c utilities.c

all:
	@gcc -g $(SRC) -L. -lftprintf -I../get_next_line -I../printf_v2 -I../libft -o qnguyen.filler
	@rm game_result
	@rm output
	@touch output
	@resourceslinux/filler_vm -v -f resourceslinux/maps/map00 -p1 ./qnguyen.filler -p2 ./resourceslinux/players/cgamora.filler > game_result

m : $(NAME)

$(NAME): $(SRC)
	@gcc -g $(SRC) -L. -lftprintf -I../get_next_line -I../printf_v2 -I../libft -o qnguyen.filler

clean:
	@rm -f qnguyen.filler