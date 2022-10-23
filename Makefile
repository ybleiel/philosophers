# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 12:00:12 by ybleiel           #+#    #+#              #
#    Updated: 2022/06/10 12:09:49 by ybleiel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc -Wall -Wextra -Werror
LIBS	:= -pthread
LEAKCHK	:= -fsanitize=address
SRC		:= main.c utils.c init.c time.c actions.c death.c forks.c
NAME	:= philo

all: $(NAME)
	
leaks: 
	$(CC) $(SRC) -o $(NAME)

re: fclean all

clean:

fclean:
	rm -f philo

$(NAME): $(SRC)
	$(CC) $^ -o $@