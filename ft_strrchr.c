#include "libft.h"

// returns a pointer to the last occurrence of the character c in  the  string
char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (index && s[index] != c)
		index--;
	if (s[index] == c)
		return ((char *)&(s[index]));
	return (0);
}
