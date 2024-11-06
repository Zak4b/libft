/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:12:50 by asene             #+#    #+#             */
/*   Updated: 2024/11/06 14:54:08 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t element_size)
{
	void	*ptr;
	size_t	total_size;

	if (count == 0 || element_size == 0)
	{
		count = 1;
		element_size = 1;
	}
	total_size = count * element_size;
	if (total_size / count != element_size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, total_size);
	return (ptr);
}
