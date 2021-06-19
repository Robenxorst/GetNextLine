#include <stdio.h>
#include <fcntl.h> // open
#include <stdlib.h> // malloc, free
#include <unistd.h> // write, read
#include "../Libft/libft/libft.h"

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

int	get_next_line(int fd, char **line)// 1, 0, -1
{
	char		buf[10 + 1];
	int			CollByteRead;
	char		*pointerN;
	int			flag;
	static char	*poterya;

	flag = 1;

	if (poterya)
		*line = ft_strdup(poterya);
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
