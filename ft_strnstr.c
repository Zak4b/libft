#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	i;
	int		needle_len;

	if (needle == NULL || *needle == '\0')
		return ((char *)str);
	i = 0;
	needle_len = ft_strlen(needle);
	if (n < (unsigned int)needle_len)
		return (NULL);
	while (str[i] && i < n - needle_len + 1)
	{
		if (ft_strncmp(str + i, needle, needle_len) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
