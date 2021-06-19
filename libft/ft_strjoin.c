#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	m;
	char	*pointer;
	char	*rez;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	pointer = (char *)malloc(sizeof(char const) * (m + n + 1));
	if (pointer == NULL)
		return (NULL);
	rez = pointer;
	while (n != 0)
	{
		*pointer++ = *s1++;
		n--;
	}
	while (m != 0)
	{
		*pointer++ = *s2++;
		m--;
	}
	*pointer = '\0';
	return (rez);
}
