#include "libft.h"

static int	char_in_str(const char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (*str != '\0');
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*new_str;
	char	*start;
	char	*last_char;

	start = (char *)str;
	while (*start && char_in_str(set, *start))
		start++;
	if (*(start + 1) == '\0')
		last_char = start;
	else
		last_char = start + ft_strlen(start) - 1;
	while (last_char > start && char_in_str(set, *last_char))
		last_char--;
	new_str = malloc(sizeof(char) * (last_char - start + 2));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, start, last_char - start + 2);
	return (new_str);
}
