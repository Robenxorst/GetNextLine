#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*dest1;
	const char		*src1;
	unsigned int	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	dest1 = (char *)dest;
	src1 = (const char *)src;
	while (i < n)
	{
		*dest1++ = *src1++;
		i++;
	}
	return (dest);
}
