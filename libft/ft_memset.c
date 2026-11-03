/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:05:38 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/28 11:53:54 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	*str;
	unsigned char	ch;
	size_t			i;

	str = s;
	ch = c;
	i = 0;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (str);
}
int	main()
{
	int arr[] = {7, 2, 3, 4};

	ft_memset(arr, 1, 1);
	ft_memset(arr +1, 0, 3);
	printf("%d\n", arr[0]);
}
