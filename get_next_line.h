#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2, char **s3, int *ret);
int			get_next_line(int fd, char **line);
int			memory_of_brain(char **brain, char **line);
int			N_in_buf(char *buf);

#endif
