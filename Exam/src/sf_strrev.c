/* ************************************************************************** */
/*                                                                            */
/*   sf_strrev.c                                      ███████╗███████╗        */
/*   By: sohaib <sohaib@student.com>                  ██╔════╝██╔════╝        */
/*   Created: 2026/10/06 00:10:39 by sohaib           ███████╗█████╗          */
/*   Updated: 2026/10/06 00:10:39 by sohaib           ╚════██║██╔══╝          */
/*                                                    ███████║██║             */
/*                                                    ╚══════╝╚═╝             */
/* ************************************************************************** */

char	*sf_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = 0;
	while(str[len])
		len++;
	len--;
	while(i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;

		i++;
		len--;
	}
	return (str);
}
#include <stdio.h>
int		main()
{
	char	s[] = "biahos";

	printf("%s\n", sf_strrev(s));
}
