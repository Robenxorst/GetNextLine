#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	minus = 0;
	res = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		minus = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = 10 * res;
		res = res + (str[i] - 48);
		i++;
	}
	if (minus)
		return (-res);
	return (res);
}
