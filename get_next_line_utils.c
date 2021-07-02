#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, char **s3, int *ret)
{
	size_t	n;
	size_t	m;
	char	*pointer;
	char	*rez;

	n = ft_strlen(s1);
	m = ft_strlen(s2);
	pointer = (char *)malloc(sizeof(char) * (m + n + 1));
	if (pointer == NULL)
	{
		*ret = -1;
		return (NULL);
	}
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

int	N_in_buf(char *buf)
{
	int		i;
	char	*pointer;

	i = 0;
	pointer = buf;
	while (*pointer != '\0' && *pointer != '\n')
	{
		pointer++;
		i++;
	}
	buf[i] = '\0';
	return (i);
}

int	memory_of_brain(char **brain, char **line)
{
	int	i;
	int	n;
	int	ret;

	i = 0;
	ret = 0;
	if (*brain == NULL)
		return (ret);
	n = ft_strlen(*brain);
	while ((*brain)[i] != '\0' && (*brain)[i] != '\n')
		i++;
	if (i != n)
	{
		ret = 1;
		(*brain)[i] = '\0';
		*line = ft_strjoin(NULL, *brain, NULL, &ret);
		*brain = ft_strjoin(NULL, (*brain) + i + 1, brain, &ret);
	}
	return (ret);
}
