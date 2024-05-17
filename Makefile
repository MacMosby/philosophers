# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 15:02:58 by mrodenbu          #+#    #+#              #
#    Updated: 2024/04/02 15:03:01 by mrodenbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	main.c philo.c ft_atoi.c get_timestamp.c init_threads.c join_threads.c \
		init_mutexes.c destroy_mutexes.c init_eating_times.c \
		check_philos_living.c routine.c

OBJ = $(SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -pthread

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean:		clean
	rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
