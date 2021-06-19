#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*begin;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	begin = res;
	while (*s1)
		*res++ = *s1++;
	*res = '\0';
	return (begin);
}
