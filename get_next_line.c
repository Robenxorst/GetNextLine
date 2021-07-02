#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

int	read_file(int fd, char *buf, char **line, long int rd)
{
	static char	*brain;
	int			ret;
	int			n;

	ret = memory_of_brain(&brain, line);
	while (ret == 0 && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (-1);
		buf[rd] = '\0';
		n = N_in_buf(buf);
		if (n != rd)
		{
			ret = 1;
			*line = ft_strjoin(brain, buf, NULL, &ret);
			brain = ft_strjoin(NULL, buf + n + 1, &brain, &ret);
		}
		else if (rd == 0)
			*line = ft_strjoin(NULL, brain, &brain, &ret);
		else
			brain = ft_strjoin(brain, buf, &brain, &ret);
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			ret;
	long int	rd;

	rd = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	ret = read_file(fd, buf, line, rd);
	free(buf);
	return (ret);
}
