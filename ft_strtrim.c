/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:16:30 by asene             #+#    #+#             */
/*   Updated: 2024/11/07 15:41:42 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_str(const char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (*str != '\0');
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		i;

	while (*str && char_in_str(set, *str))
		str++;
	if (*str == '\0')
		i = 0;
	else
		i = ft_strlen(str) - 1;
	while (&(str[i]) > str && char_in_str(set, str[i]))
		i--;
	return (ft_substr(str, 0, i + 1));
}
