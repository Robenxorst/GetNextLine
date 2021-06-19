#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*pointer;
	char		*rezult;
	size_t		n;

	if (s == 0)
		return (NULL);
	n = 0;
	while (s[n] != '\0')
		n++;
	pointer = (char *)malloc(sizeof(char) * (n + 1));
	if (pointer == NULL)
		return (NULL);
	rezult = pointer;
	n = 0;
	while (s[n] != 0)
	{
		*pointer++ = f(n, s[n]);
		n++;
	}
	*pointer = '\0';
	return (rezult);
}
