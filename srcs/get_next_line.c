/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:24:40 by asene             #+#    #+#             */
/*   Updated: 2025/02/07 19:01:20 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "get_next_line.h"
#include <unistd.h>

static size_t	line_lenght(t_list *lst)
{
	size_t	line_len;
	char	*newline;

	line_len = 0;
	newline = NULL;
	while (lst && !newline)
	{
		newline = ft_strchr(lst->content, '\n');
		if (newline == NULL)
			line_len += ft_strlen(lst->content);
		else
			line_len += newline - (char *)lst->content +1;
		lst = lst->next;
	}
	return (line_len);
}

static char	*extract_line(t_list **stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*line;
	void	*tmp;

	len = line_lenght(*stash);
	line = ft_calloc(len +1, sizeof(char));
	i = 0;
	while (i < len)
	{
		j = 0;
		while (i < len && ((char *)(*stash)->content)[j])
			line[i++] = ((char *)(*stash)->content)[j++];
		if (ft_strchr("\n",((char *)(*stash)->content)[j]) != NULL)
		{
			tmp = *stash;
			(*stash) = (*stash)->next;
			ft_lstdelone(tmp, free);
		}
	}
	if (*stash)
	{	
		tmp = (*stash)->content;
		(*stash)->content = ft_substr((*stash)->content, j, BUFFER_SIZE);
		free(tmp);
	}
	return (line);
}

static void	gnl_readline(int fd, t_list **stash)
{
	char	*read_buffer;

	while (1)
	{
		read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (read(fd, read_buffer, BUFFER_SIZE) == 0)
		{
			free(read_buffer);
			break ;
		}
		ft_lstadd_back(stash, ft_lstnew(read_buffer));
		if (ft_strchr(read_buffer, '\n'))
			break;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_lstclear(&stash, free);
		return (NULL);
	}
	gnl_readline(fd, &stash);
	if (stash == NULL)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
