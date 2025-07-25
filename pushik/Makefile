NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC = src/operations/push.c \
	  src/operations/swap.c \
	  src/operations/rotate.c \
	  src/operations/rev_rotate.c \
	  src/stack_utils.c \
	  src/big_sort_utils.c \
	  src/cost_utils.c \
	  src/ft_utils.c \
	  src/small_sort_utils.c \
	  src/stack_utils2.c \
	  src/big_sort_utils2.c \
	  src/big_sort.c \
	  src/small_sort.c \
	  src/checks.c \
	  src/main.c \
	  src/sort_helpers.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
