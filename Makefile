CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCS)

SRCS = madatory/push_swap.c madatory/ft_split.c madatory/errors.c madatory/valid.c \
	   madatory/initialize.c madatory/swap.c madatory/push.c madatory/rotate.c \
	   madatory/rev_rotate.c madatory/indexes.c madatory/sorting.c madatory/butterfly.c \
	   madatory/log.c 

BONUS_SRCS = checker/get_next_line.c checker/get_next_line_utils.c checker/checker.c \
	   checker/ft_split.c checker/errors.c checker/valid.c checker/initialize.c \
	   checker/swap.c checker/push.c checker/rotate.c checker/rev_rotate.c \
	   checker/indexes.c checker/checker_utils.c checker/sorting.c

INCS = ./

NAME = push_swap
BONUS_NAME = checker

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
