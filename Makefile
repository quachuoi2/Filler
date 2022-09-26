# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 21:27:32 by qnguyen           #+#    #+#              #
#    Updated: 2022/09/26 08:40:09 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = qnguyen.filler
SRCS = ./srcs/
FILE = main algo utilities get axis border reader
ANIME = animate.c reader.c utilities.c get.c border.c
INCLUDES = ./includes
LIB = libft.a
LIB_DIR = ./libft/
PRINTF = libftprintf.a
PRINTF_DIR = ./ft_printf
OBJS = ./objs/

all: $(NAME)

$(NAME): $(addprefix $(OBJS), $(addsuffix .o, $(FILE)))
	gcc $^ -L. -lftprintf -I $(INCLUDES) -o qnguyen.filler -Ofast

$(OBJS)%.o: $(SRCS)%.c $(PRINTF_DIR)
	gcc -c $< -L. -lftprintf -I $(INCLUDES) -o $@ -Ofast

$(PRINTF_DIR): $(LIB)
	make -C $(PRINTF_DIR)

$(LIB):
	make -C $(LIB_DIR)
	@cp ./libft.a $(PRINTF_DIR)

p1:
	@resourceslinux/filler_vm -v -f resourceslinux/maps/map00 -p1 ./qnguyen.filler -p2 ./resourceslinux/players/cgamora.filler > game_result

p2:
	@resources/filler_vm -v -f resources/maps/map00 -p2 ./qnguyen.filler -p1 ./resources/players/abanlin.filler > game_result

anime:
	@gcc -O3 $(ANIME) -L. -lftprintf -I $(INCLUDES)

clean:
	@/bin/rm -f $(addprefix $(OBJS), $(addsuffix .o, $(FILES)))
	@make clean -C $(LIB_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(PRINTF_DIR)
	@/bin/rm -f libftprintf.a
	@/bin/rm -f game_result
	@/bin/rm -f filler.trace
	@/bin/rm -rf objs
re: fclean all
