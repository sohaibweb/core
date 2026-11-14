CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -I include

SRCS = main.c \
	operations/ft_swap.c \
	operations/ft_push.c \
	operations/ft_rotate.c \
	operations/ft_reverse_rotate.c \
	utils/ft_lst_utils.c \
	utils/ft_str_utils.c \
	utils/ft_split.c \
	utils/ft_substr.c \
	utils/ft_utils.c \
	sorting/ft_sort_small.c \
	sorting/disorder.c \
	sorting/push_swap.c \
	sorting/indixing.c \
	Alg/selection.c \
	Alg/chunk.c \
	Alg/chunk_push_to_a.c \
	Alg/radix.c \
	parsing/ft_check_args.c \
	benchmark/ft_bench.c \
	benchmark/ft_bench_print.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rfv $(OBJS)

fclean: clean
	rm -rfv $(NAME)

re: fclean all

.PHONY: all clean fclean re