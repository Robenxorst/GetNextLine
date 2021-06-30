#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h> // open
#include <stdlib.h> // malloc, free
#include <unistd.h> // write, read

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 64
#endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2, char **s3);
int		get_next_line(int fd, char **line);
int		remains_n(char **remains, char **line);
int		buf_check(char *buf);

#endif
