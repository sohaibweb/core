CC = cc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_putchar.c\
       ft_putstr.c\
       ft_putnbr.c\
       ft_putptr.c\
       ft_putnbr_hex.c\
       ft_putnbr_unsigned.c\
       ft_printf.c

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
