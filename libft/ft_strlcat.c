#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	m;

	n = 0;
	m = ft_strlen(src);
	n = ft_strlen(dst);
	if (size <= n)
		return (m + size);
	m = m + n;
	dst = dst + n;
	while ((*src) && (n < (size - 1)))
	{
		*dst++ = *src++;
		n++;
	}
	*dst = '\0';
	return (m);
}
