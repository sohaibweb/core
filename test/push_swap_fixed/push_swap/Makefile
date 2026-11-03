CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -I include

SRCS = main.c \
	operations/ft_swap.c \
	operations/ft_push.c \
	operations/ft_rotate.c \
	operations/ft_reverse_rotate.c \
	parsing/ft_check_args.c \
	parsing/ft_parse.c \
	sorting/disorder.c \
	sorting/ft_sort_small.c \
	sorting/indicing.c \
	sorting/push_swap.c \
	sorting/push_to_a.c \
	sorting/radix.c \
	sorting/selection.c \
	sorting/sort_big.c \
	utils/ft_bench.c \
	utils/ft_ctx.c \
	utils/ft_lst_utils.c \
	utils/ft_put.c \
	utils/ft_split.c \
	utils/ft_str_utils.c \
	utils/ft_substr.c \
	utils/ft_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c include/ft_push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
