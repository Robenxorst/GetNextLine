#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	n;

	if (s == 0)
		return ;
	n = 0;
	while (s[n] != '\0')
	{
		write (fd, &s[n], sizeof(char));
		n++;
	}
}
