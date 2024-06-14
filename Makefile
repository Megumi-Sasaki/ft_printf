NAME = libftprintf.a
SRCS = ${wildcard *.c}
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar	-rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all re clean fclean