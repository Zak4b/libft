#include "libft.h"

static int	count_word(char const *str, char c)
{
	int	wc;

	wc = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			wc++;
		while (*str && *str != c)
			str++;
	}
	return (wc);
}

static char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**string_array;

	string_array = malloc(sizeof(char *) * (count_word(str, c) + 1));
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
		{
			string_array[k] = malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(string_array[k++], &str[j], i - j);
		}
	}
	string_array[k] = NULL;
	return (string_array);
}
// free on element malloc error
