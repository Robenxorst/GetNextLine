#include <stdio.h>
#include <fcntl.h> // open
#include <stdlib.h> // malloc, free
#include <unistd.h> // write, read
//#include "../Libft/libft/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

size_t	ft_strlen(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	str = (char*)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = s[len];
		len--;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	res = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (res);
}

int	get_next_line(int fd, char **line)// 1, 0, -1
{
	char		buf[10 + 1];
	int			CollByteRead;
	char		*pointerN;
	int			flag;
	static char	*poterya;

	flag = 1;
	if (poterya)
	{
		*line = ft_strdup(poterya);
		//printf("%s", poterya);
	}
	else
		*line = ft_strnew(1);
	while ((CollByteRead = read (fd, buf, 10)) && flag)// a hidden\n\0
	{
		buf[CollByteRead] = '\0';
		if ((pointerN = ft_strchr(buf, '\n')))
		{
			*pointerN = '\0';
			flag = 0;
			pointerN++;
			poterya = ft_strdup(pointerN);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int main()
{
	char	*line;
	int		fd;

	fd = open ("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf ("%s\n", line);

	get_next_line(fd, &line);
	printf ("%s\n", line);
}
