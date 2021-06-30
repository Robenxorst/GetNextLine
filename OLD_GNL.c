#include "get_next_line.h"
#include <stdio.h>

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

int		get_next_line(int fd, char **line)// 1, 0, -1
{
	char		*buf;
	int			CollByteRead;
	char		*pointerN;
	int			flag;
	static char	*poterya;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	flag = 1;
	if (poterya)
		*line = ft_strdup(poterya);
	else
		*line = '\0';
	while (flag && (CollByteRead = read (fd, buf, 10)))// a hidden\n\0
	{
		buf[CollByteRead] = '\0';
		if ((pointerN = ft_strchr(buf, '\n')))
		{
			*pointerN = '\0';
			flag = 0;
			pointerN++;
			poterya = ft_strdup(pointerN);
		}
		*line = ft_strjoin(*line, buf, NULL);
	}
	if (flag == 0)
		return (1);
	if (CollByteRead == 0)
		return (0);
	return (-1);
}

int main(void)
{
    char    *line;
    int     fd;

    fd = open ("test.txt", O_RDONLY);
    while (get_next_line(fd, &line) == 1)
        printf ("%s\n", line);
    if (get_next_line(fd, &line) == -1)
        printf ("KolyaDurak");
    if (get_next_line(fd, &line) == 0)
        printf("Successfull reading");
}

