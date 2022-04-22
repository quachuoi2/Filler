# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 21:27:32 by qnguyen           #+#    #+#              #
#    Updated: 2022/04/21 09:28:51 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = qnguyen.filler
SRC = main.c algo.c utilities.c get.c axis.c border.c reader.c
ANIME = animate.c reader.c utilities.c get.c border.c
INCLUDES = ./includes/
LIB_DIR = ./libft/
PRINTF_DIR = ./ft_printf

all:
	make -C ./$(LIB_DIR)
	make -C ./$(PRINTF_DIR)
	gcc -c -O3 ./GNL/get_next_line.c -I $(INCLUDES)
	mv ./$(PRINTF_DIR)/libftprintf.a .
	ar rcs libftprintf.a get_next_line.o
	gcc -O3 $(SRC) -L. -lftprintf -I $(INCLUDES) -o qnguyen.filler
	@rm game_result
	@rm output
	@touch output

m :
	@gcc -O3 $(SRC) -L. -lftprintf -I $(INCLUDES) -o qnguyen.filler

p1:
	@resources/filler_vm -v -f resources/maps/map00 -p1 ./qnguyen.filler -p2 ./resources/players/superjeannot.filler > game_result

p2:
	@resources/filler_vm -v -f resources/maps/map00 -p2 ./qnguyen.filler -p1 ./resources/players/abanlin.filler > game_result

anime:
	@gcc -O3 $(ANIME) -L. -lftprintf -I $(INCLUDES)

clean:
	/bin/rm -f $(addsuffix .o, $(SRCS)) get_next_line.o
	make -C $(LIB_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIB_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all
