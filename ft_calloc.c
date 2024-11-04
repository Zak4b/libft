/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:12:50 by asene             #+#    #+#             */
/*   Updated: 2024/11/04 14:12:51 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t element_size)
{
	void	*ptr;

	if (count == 0 || element_size == 0)
	{
		count = 1;
		element_size = 1;
	}
	ptr = malloc(count * element_size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, count * element_size);
	return (ptr);
}
