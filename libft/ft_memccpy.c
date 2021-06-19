#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)dest)[i] == (unsigned char)c)
			return (&dest[++i]);
		i++;
	}
	return (NULL);
}
