#include <unistd.h>

int	check_chr(char c, char *arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		if (arr[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 1;
	if (argc > 2)
	{
		while (argv[1][i])
		{
			if (!check_chr(argv[1][i], argv[2]))
			{
				check = 0;
				break;
			}
			else
				i++;
		}
		if (check)
		{
			i = 0;
			while(argv[1][i])
				write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
}
