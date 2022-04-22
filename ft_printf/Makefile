# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:35:47 by qnguyen           #+#    #+#              #
#    Updated: 2022/04/21 08:30:21 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = libftprintf prefix utilities utilities_2 printer flags_handler\
conversion_prefix_adapter
FLAGS = -Wall -Wextra -Werror
NITPICK = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
LIB_DIR = ../libft/
LIB = -lft

all: $(NAME)

$(NAME):$(addsuffix .c, $(SRCS))
	make -C $(LIB_DIR)
	gcc -c -O3 $(addsuffix .c, $(SRCS)) $(FLAGS) -I$(LIB_DIR)
	cp $(LIB_DIR)libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(addsuffix .o, $(SRCS))

m:
	@gcc -g -O3 $(addsuffix .c, $(SRCS)) main.c -L$(LIB_DIR) $(LIB) -I$(LIB_DIR)
	@./a.out
clean:
	@/bin/rm -f $(addsuffix .o, $(SRCS))
	@make -C $(LIB_DIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@/bin/rm -f a.out

re: fclean all
