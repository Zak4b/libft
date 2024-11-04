#include "libft.h"

// fills n bytes of the memory area pointed to by s with the constant byte c
// return a pointer to the matching byte or NULL
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		ptr[n] = c;
	return (s);
}
