#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	n;
	char	c;

	if (s == 0)
		return ;
	n = 0;
	c = '\n';
	while (s[n] != '\0')
	{
		write (fd, &s[n], sizeof(char));
		n++;
	}
	write (fd, &c, sizeof(char));
}
