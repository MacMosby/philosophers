# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 15:55:48 by mrodenbu          #+#    #+#              #
#    Updated: 2024/08/17 15:55:50 by mrodenbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

SRC := check_status.c clean_data.c dead_check.c destroy_mutexes.c ft_atoi.c \
		ft_calloc.c ft_isdigit.c ft_strncmp.c get_timestamp.c init_data.c \
		init_mutex_memory.c init_mutexes.c isint.c main.c p_mutex.c routine.c \
		set_start_time.c threads.c

OBJ := $(SRC:%.c=%.o)

CC := cc

CFLAGS := -Wall -Werror -Wextra -g3 -fsanitize=thread
#-fsanitize=address

LINK_OPTION := -pthread

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(LINK_OPTION) -o $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
