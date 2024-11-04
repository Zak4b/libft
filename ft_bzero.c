#include "libft.h"

// write n "zeros" bytes to that area.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
