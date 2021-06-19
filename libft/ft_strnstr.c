#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while ((haystack[i]) && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] && ((j + i) < len))
			{
				if (needle[j] != haystack[i + j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
