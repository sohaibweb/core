#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	fprintf(stderr, "putstr:  %d\n", ft_putstr("Hello"));
	fprintf(stderr, "putnbr:  %d\n", ft_putnbr(21474));
	fprintf(stderr, "unsigned:%d\n", ft_putnbr_unsigned(4294967295u));
	fprintf(stderr, "hex:     %d\n", ft_putnbr_hex(255, 'x'));
	fprintf(stderr, "ptr:     %d\n", ft_putptr(&main));
	fprintf(stderr, "printf:  %d\n", ft_printf("%d %s %x %c %%\n", 42, "hi", 255, 'z'));
	return (0);
}
