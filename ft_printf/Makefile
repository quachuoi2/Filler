# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:35:47 by qnguyen           #+#    #+#              #
#    Updated: 2022/09/26 08:41:04 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a
LIB = libft.a
SRCS = libftprintf prefix utilities utilities_2 printer flags_handler conversion_prefix_adapter
OBJS = ../objs/
FLAGS = -Wall -Wextra -Werror
NITPICK = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
INCLUDES = ../includes/

all: $(NAME)

$(NAME): $(addprefix $(OBJS), $(addsuffix .o, $(SRCS)))
	mv $(LIB) $(NAME)
	ar -rcs $(NAME) $(addprefix $(OBJS), $(addsuffix .o, $(SRCS)))

$(OBJS)%.o: %.c
	gcc -c $< -I$(INCLUDES) $(FLAGS) -o $@ -Ofast #remove Ofast for Linux

clean:
	@/bin/rm -f $(addprefix $(OBJS), $(addsuffix .o, $(SRCS)))

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all
