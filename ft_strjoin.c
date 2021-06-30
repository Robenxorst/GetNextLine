
#include "get_next_line.h"
#include <stdio.h>

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2, char **s3)
{
	size_t	n;
	size_t	m;
	char	*pointer;
	char	*rez;

	n = ft_strlen(s1);
	m = ft_strlen(s2);
	pointer = (char *)malloc(sizeof(char) * (m + n + 1));
	if (pointer == NULL)
		return (NULL);
	rez = pointer;
	while (s1 && (*s1 != '\0'))
		*pointer++ = *s1++;
	while (s2 && (*s2 != '\0'))
		*pointer++ = *s2++;
	*pointer = '\0';
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
	return (rez);
}

int main()
{
	char	*result;
	char	lol1[20] = "Danya";
	char	lol2[20] = "Vasya";
	char	*lol3;
	char	*firstFree;
	int		n;

	lol3 = (char *)malloc(sizeof(char) * 4);
	firstFree = lol3;
	*lol3 = 'P';
	lol3++;
	*lol3 = 'S';
	lol3++;
	*lol3 = '5';
	lol3++;
	*lol3 = '\0';
	printf("%s\n",firstFree);
	result = ft_strjoin(lol1, lol2, &firstFree);
	printf("%s\n", result);
	printf("%s\n",firstFree);
	return (0);
}
