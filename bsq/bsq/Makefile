# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialleen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 10:26:24 by ialleen           #+#    #+#              #
#    Updated: 2019/08/20 11:33:51 by ialleen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq 

SOURCES	= srcs/check_valid_file.c srcs/file_to_mas.c \
		  srcs/ft_putstr.c srcs/list_error.c srcs/main.c \
		  srcs/find_square.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra $(SOURCES) -o $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
