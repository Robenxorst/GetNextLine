#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", sizeof(char) * ft_strlen("-2147483648"));
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", sizeof(char));
	}
	c = n % 10 + '0';
	if (n >= 0 && n <= 9)
	{
		write(fd, &c, sizeof(char));
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	write(fd, &c, sizeof(char));
}
