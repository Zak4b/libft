/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:20 by asene             #+#    #+#             */
/*   Updated: 2024/11/05 12:17:32 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **array, int size)
{
	while (size-- > 0)
		free(array[size]);
	free(array);
}

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

static char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup == NULL)
		return (NULL);

	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *str, char c)
{
	char	*start;
	int		k;
	char	**string_array;

	if ((string_array = malloc(sizeof(char *) * (count_word(str, c) + 1))) == NULL)
		return (NULL);
	k = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		start = (char *)str;
		while (*str && *str != c)
			str++;
		if (str > start)
		{
			if ((string_array[k++] = ft_strndup(start, str - start))==NULL)
			{
				free_split(string_array, k);
				return (NULL);
			}
		}
	}
	string_array[k] = NULL;
	return (string_array);
}
