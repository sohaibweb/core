#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{
	int		n1;
	int		n2;
	int		x;
	char	*s;

	x = 42;
	s = "sohaib";

	printf("\n========== %%c ==========\n");

	n1 = printf("printf    : [%c]\n", 'A');
	n2 = ft_printf("ft_printf : [%c]\n", 'A');
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%c]\n", ' ');
	n2 = ft_printf("ft_printf : [%c]\n", ' ');
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%c%c%c]\n", 'A', 'B', 'C');
	n2 = ft_printf("ft_printf : [%c%c%c]\n", 'A', 'B', 'C');
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%s ==========\n");

	n1 = printf("printf    : [%s]\n", "hello");
	n2 = ft_printf("ft_printf : [%s]\n", "hello");
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%s]\n", "");
	n2 = ft_printf("ft_printf : [%s]\n", "");
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%s]\n", s);
	n2 = ft_printf("ft_printf : [%s]\n", s);
	printf("return     : %d / %d\n", n1, n2);
	n1 = printf("printf    : [%s]\n", (char *)NULL);
	n2 = ft_printf("ft_printf : [%s]\n", (char *)NULL);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%p ==========\n");

	n1 = printf("printf    : [%p]\n", (void *)&x);
	n2 = ft_printf("ft_printf : [%p]\n", (void *)&x);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%p]\n", (void *)NULL);
	n2 = ft_printf("ft_printf : [%p]\n", (void *)NULL);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%p]\n", (void *)s);
	n2 = ft_printf("ft_printf : [%p]\n", (void *)s);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%d ==========\n");

	n1 = printf("printf    : [%d]\n", 0);
	n2 = ft_printf("ft_printf : [%d]\n", 0);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%d]\n", 42);
	n2 = ft_printf("ft_printf : [%d]\n", 42);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%d]\n", -42);
	n2 = ft_printf("ft_printf : [%d]\n", -42);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%d]\n", INT_MAX);
	n2 = ft_printf("ft_printf : [%d]\n", INT_MAX);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%d]\n", INT_MIN);
	n2 = ft_printf("ft_printf : [%d]\n", INT_MIN);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%i ==========\n");

	n1 = printf("printf    : [%i]\n", 0);
	n2 = ft_printf("ft_printf : [%i]\n", 0);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%i]\n", 12345);
	n2 = ft_printf("ft_printf : [%i]\n", 12345);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%i]\n", -12345);
	n2 = ft_printf("ft_printf : [%i]\n", -12345);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%i]\n", INT_MAX);
	n2 = ft_printf("ft_printf : [%i]\n", INT_MAX);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%i]\n", INT_MIN);
	n2 = ft_printf("ft_printf : [%i]\n", INT_MIN);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%u ==========\n");

	n1 = printf("printf    : [%u]\n", 0u);
	n2 = ft_printf("ft_printf : [%u]\n", 0u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%u]\n", 42u);
	n2 = ft_printf("ft_printf : [%u]\n", 42u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%u]\n", 4294967295u);
	n2 = ft_printf("ft_printf : [%u]\n", 4294967295u);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%x ==========\n");

	n1 = printf("printf    : [%x]\n", 0u);
	n2 = ft_printf("ft_printf : [%x]\n", 0u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%x]\n", 42u);
	n2 = ft_printf("ft_printf : [%x]\n", 42u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%x]\n", 255u);
	n2 = ft_printf("ft_printf : [%x]\n", 255u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%x]\n", 4294967295u);
	n2 = ft_printf("ft_printf : [%x]\n", 4294967295u);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%X ==========\n");

	n1 = printf("printf    : [%X]\n", 0u);
	n2 = ft_printf("ft_printf : [%X]\n", 0u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%X]\n", 42u);
	n2 = ft_printf("ft_printf : [%X]\n", 42u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%X]\n", 255u);
	n2 = ft_printf("ft_printf : [%X]\n", 255u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%X]\n", 4294967295u);
	n2 = ft_printf("ft_printf : [%X]\n", 4294967295u);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== %%%% ==========\n");

	n1 = printf("printf    : [%%]\n");
	n2 = ft_printf("ft_printf : [%%]\n");
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [100%%]\n");
	n2 = ft_printf("ft_printf : [100%%]\n");
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%%%%%%]\n");
	n2 = ft_printf("ft_printf : [%%%%%%]\n");
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== MIXED ==========\n");

	n1 = printf("printf    : [%c %s %d %i %u %x %X %%]\n",
		'A', "hello", -42, 42, 42u, 255u, 255u);
	n2 = ft_printf("ft_printf : [%c %s %d %i %u %x %X %%]\n",
		'A', "hello", -42, 42, 42u, 255u, 255u);
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%d %d %d %d]\n",
		INT_MIN, -1, 0, INT_MAX);
	n2 = ft_printf("ft_printf : [%d %d %d %d]\n",
		INT_MIN, -1, 0, INT_MAX);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== NORMAL TEXT ==========\n");

	n1 = printf("printf    : hello world\n");
	n2 = ft_printf("ft_printf : hello world\n");
	printf("return     : %d / %d\n", n1, n2);

	n1 = printf("printf    : [%s %d %x]\n", "sohaib", 42, 255);
	n2 = ft_printf("ft_printf : [%s %d %x]\n", "sohaib", 42, 255);
	printf("return     : %d / %d\n", n1, n2);


	printf("\n========== SPECIAL FORMAT CASES ==========\n");

	n1 = ft_printf("ft_printf : [%%]");
	printf("\nreturn = %d\n", n1);

	n1 = ft_printf("ft_printf : [%%%%]");
	printf("\nreturn = %d\n", n1);

	n1 = ft_printf("ft_printf : [abc%%def]");
	printf("\nreturn = %d\n", n1);

	return (0);
}
