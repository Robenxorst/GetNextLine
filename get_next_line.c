#include "get_next_line.h"
#include <stdio.h>

int	read_file(int fd, char *buf, char **line, ssize_t len)//0-файл кончился нечего читать,1-есть что читать
{
	static char	*remains;
	int			k;
	int			i;

	k = remains_n(&remains, line);//1- есть слеш н, 0 - нет слеш н в статическом воспоминании
	while ((k != 1) && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)//вариант с ошибкой чтения
			return (-1);
		buf[len] = '\0';
		i = buf_check(buf);//находим номер слеш н в строке
		if (i < len)//если слеш н был найден,то закидываем в лайн ремайнс и часть буфера до н
		{
			*line = ft_strjoin(remains, buf, NULL);
			remains = ft_strjoin(NULL, buf + i + 1, &remains);//в воспоминание все,что после слеш н
			k = 1;//цикл завершается
		}
		if (len == 0)//чтение закончилось,мы кидаем воспоминание в лайн и затираем его
			*line = ft_strjoin(NULL, remains, &remains);
		if (i == len)
			remains = ft_strjoin(remains, buf, &remains);//кидаем в воспоминание буфер
	}
	free (buf);
	return (k);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	int		k;
	ssize_t	len;

	k = 0;//возвращаемое значение
	len = 1;//количество считываемых символов
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	k = read_file(fd, buf, line, len);
	if (k == (-1))
		free(buf);
	return (k);
}

