#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return(0);
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

int			buf_check(char *buf)// ищем символ слеш н и затираем его нуль символом
{
	int	i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	return (i);
}

int	remains_n(char **remains, char **line)//работа со статическим воспоминанием
{
	int	i;
	int	len;

	i = 0;
	if (*remains == NULL)
		return (0);
	len = ft_strlen(*remains);
	while ((*remains)[i] != '\0' && (*remains)[i] != '\n')
		i++;
	if (i < len)//вариант остановки,когда наткнулись на слеш н
	{
		(*remains)[i] = '\0';
		*line = ft_strjoin(NULL, *remains, NULL);//запихиваем в линию статическую переменную
		*remains = ft_strjoin(NULL, (*remains) + i + 1, remains);//затираем старую статич перемен и записываем со слеш нуля ремайнс
		return (1);//еденица если есть слеш н
	}
	return (0);
}
