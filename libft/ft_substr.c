#include "libft.h"

static char	*big_size_of_start(char const *s)
{
	char	*pointer;

	pointer = (char *)(malloc(sizeof(*s)));
	if (pointer == NULL)
		return (NULL);
	pointer[0] = '\0';
	return (pointer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	char	*res;
	size_t	n;
	size_t	i;

	if (s == 0)
		return (NULL);
	i = start;
	n = 0;
	while ((s[i] != '\0') && (n < len))
	{
		i++;
		n++;
	}
	if (start >= ft_strlen(s))
		return (big_size_of_start(s));
	pointer = (char *)malloc(sizeof(char const) * (n + 1));
	if (pointer == NULL)
		return (NULL);
	s = s + start;
	res = pointer;
	while ((n--) != 0)
		*pointer++ = *s++;
	*pointer = '\0';
	return (res);
}
