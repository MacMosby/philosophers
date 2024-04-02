NAME = philo

SRC =	main.c

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
