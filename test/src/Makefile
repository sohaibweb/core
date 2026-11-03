CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_swap.c\
        ft_push.c\
        ft_rotate.c\
		ft_reverse_rotate.c\
        ft_push_swap_utils.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rfv $(OBJS)

fclean : clean
	rm -rfv  $(NAME)

re : fclean all

.PHONY : all clean fclean re
