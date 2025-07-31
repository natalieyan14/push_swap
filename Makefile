CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCS) -g3

INCS = ./

SRCS = madatory/push_swap.c madatory/ft_split.c madatory/errors.c madatory/valid.c \
	   madatory/initialize.c madatory/swap.c madatory/push.c madatory/rotate.c \
	   madatory/rev_rotate.c madatory/indexes.c madatory/sorting.c madatory/butterfly.c \
	   madatory/log.c 

BONUS_SRCS = checker_bonus/get_next_line.c checker_bonus/get_next_line_utils.c \
			 checker_bonus/checker.c checker_bonus/checker_utils.c

NAME = push_swap
BONUS_NAME = checker

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJS_EXCL_MAIN = $(filter-out madatory/push_swap.o, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS) $(OBJS_EXCL_MAIN)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_EXCL_MAIN) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
