CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS_BASE = command.c \
			error.c \
			main.c \
			quick_sort.c \
			radix_swap.c \
			small_swap.c \
			split.c \
			stack.c \
			util.c \
			free.c \
			simplify.c

SRCS = $(addprefix src/, $(SRCS_BASE))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re