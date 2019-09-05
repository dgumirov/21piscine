# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvincent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 11:33:58 by tvincent          #+#    #+#              #
#    Updated: 2019/08/20 16:36:14 by tvincent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

SRC = eval_exp.c ft_math.c ft_stack.c ft_func.c

HEADER = ft.h

BIBLIO = ft

all: $(NAME)

$(NAME): 
	@gcc -Wall -Wextra -Werror -I $(HEADER) -L. -l$(BIBLIO) -o $(NAME) $(SRC)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
