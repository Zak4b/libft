/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:32 by asene             #+#    #+#             */
/*   Updated: 2024/11/04 14:09:32 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns a pointer to the first occurrence of the character c in the string s
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s || c == '\0')
		return ((char *)s);
	return (0);
}
