# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 21:27:32 by qnguyen           #+#    #+#              #
#    Updated: 2022/10/03 21:51:21 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = qnguyen.filler
SRCS = ./srcs/
FILE = main algo get axis border reader filler_utilities
ANIME = animate filler_utilities animate_util
INCLUDES = -I ./includes
LIB = libft.a
LIB_DIR = ./libft/
PRINTF = libftprintf.a
PRINTF_DIR = ./ft_printf
OBJS = ./objs/
FLAG =  -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(addprefix $(OBJS), $(addsuffix .o, $(FILE)))
	gcc $^ $(FLAG) -L . $(PRINTF) $(INCLUDES) -o qnguyen.filler -Ofast

$(OBJS)%.o: $(SRCS)%.c $(PRINTF)
	gcc -c $(FLAG) $< $(INCLUDES) -o $@ -Ofast

$(PRINTF): $(LIB)
	make -C $(PRINTF_DIR)

$(LIB):
	make -C $(LIB_DIR)
	@cp ./libft.a $(PRINTF_DIR)

anime:
	@gcc -Ofast $(addprefix $(SRCS), $(addsuffix .c, $(ANIME))) -L. -lftprintf $(INCLUDES) -o anime

clean:
	@/bin/rm -rf objs
	@# /bin/rm -f $(addprefix $(OBJS), $(addsuffix .o, $(FILE)))
	@# make clean -C $(LIB_DIR)
	@# make clean -C $(PRINTF_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(PRINTF_DIR)
	@/bin/rm -f libftprintf.a
	@/bin/rm -f game_result
	@/bin/rm -f filler.trace
	@/bin/rm -f anime
re: fclean all

.PHONY: anime clean fclean re all