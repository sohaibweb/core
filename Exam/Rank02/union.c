#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	int n;
	int dup;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			n = 0;
			dup = 0;
			while (n < i)
			{
				if (argv[1][i] == argv[1][n])
					dup += 1;
				n++;
			}
			if (!dup)
				write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[2][j])
		{
			n = 0;
			dup = 0;
			while (argv[1][n])
			{
				if (argv[2][j] == argv[1][n])
					dup = 1;
				n++;
			}
			n = 0;
			while (n < j)
			{
				if (argv[2][j] == argv[2][n])
					dup = 1;
				n++;
			}
			if (!dup)
				write (1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
