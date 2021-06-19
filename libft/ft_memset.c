#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*pointer;

	pointer = (char *)b;
	while (len > 0)
	{
		*pointer++ = c;
		len--;
	}
	return (b);
}
