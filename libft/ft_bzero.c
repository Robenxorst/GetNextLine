#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*pointer;

	pointer = (char *)s;
	while (n > 0)
	{
		*pointer++ = '\0';
		n--;
	}
}
