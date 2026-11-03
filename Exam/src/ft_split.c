#include <stdlib.h>
#include <stdio.h>

int	sepa(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
	{
		return 1;
	}
	return 0;
}
int	word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !sepa(str[i]))
	{
		i++;
	}
	return i;
}
int	count_word(char *str)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if(in_word == 0 && !sepa(str[i]))
		{
			count++;
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return count;
}
char	*ft_word_dup(char *str, int len)
{
	int	i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if(!result)
	{
		return 0;
	}
	i = 0;
	while(i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return result;
}
char	**ft_split(char *str)
{
	int		i;
	int		len;
	int		word;
	int		index_word;
	char	**result;

	word = count_word(str);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if(!result)
	{
		return 0;
	}
	i = 0;
	index_word = 0;
	while (str[i] != '\0')
	{
		while(str[i] && sepa(str[i]))
		{
			i++;
		}
		if (str[i] && !sepa(str[i]))
		{
			len = word_len(&str[i]);
			result[index_word] = ft_word_dup(&str[i], len);
			index_word++;
			i +=len;
		}
	}
	result[index_word] = NULL;
	return result;
}
int	main()
{
	int		i;
	char	str[] = " sohaib       ashraf   abw msameh   in lern lang c 42 irbid   ";
	char	**result;

	result = ft_split(str);
	if(!result)
	{
		printf("\n");
	}
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return 0;
}