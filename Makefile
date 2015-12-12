# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/14 12:47:55 by mdezitte          #+#    #+#              #
#    Updated: 2015/12/07 18:13:05 by mdezitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

COMPIL = gcc -Wall -Wextra -Werror

SRC = $(shell ls -1 | grep "\.c")

HEADER = $(shell ls -1 | grep "\.h")

OBJ = $(SRC:%.c=%.o)

LIB = libft/libft.a 

TERMCAP = -L /usr/lib/ -ltermcap

all: $(NAME)

$(NAME):
		@cd libft ; $(MAKE) -f Makefile
		@$(COMPIL) -c $(SRC)
		@$(COMPIL) -o $(NAME) $(OBJ) $(LIB) $(TERMCAP)
		@echo "\033[0;32mCompilation de ft_select et libft.\033[0;33m"

clean:
		@/bin/rm -f $(OBJ)
		@cd libft ; $(PHONY make clean)
		@echo "\033[0;32mClean de ft_select et libft.\033[0;33m"

fclean: clean
		@/bin/rm -f $(NAME)
		@cd libft ; $(PHONY) make fclean
		@echo "\033[0;32mFclean de ft_select et libft.\033[0;33m"

re: fclean all
