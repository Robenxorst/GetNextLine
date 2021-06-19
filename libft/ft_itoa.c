#include "libft.h"

static int	ft_LengthString(int n)
{
	int	rez;

	rez = 0;
	while (n != 0)
	{
		n = n / 10;
		rez++;
	}
	return (rez);
}

static char	*ft_IfZero(void)
{
	char	*rez;
	char	*pointer;

	pointer = (char *)malloc(sizeof(char) * 2);
	rez = pointer;
	*pointer++ = '0';
	*pointer = '\0';
	return (rez);
}

static char	*ft_Ifminus(int n)
{
	char	*rez;
	char	*pointer;
	int		m;
	int		min;

	m = 1;
	min = -1;
	m = m + ft_LengthString(n);
	pointer = (char *)malloc(sizeof(char) * (m + 1));
	if (pointer == NULL)
		return (NULL);
	rez = pointer;
	*pointer = '-';
	pointer = pointer + m;
	*pointer-- = '\0';
	while (n != 0)
	{
		*pointer-- = min * (n % 10) + 48;
		n = n / 10;
	}
	return (rez);
}

char	*ft_itoa(int n)
{
	char	*rez;
	char	*pointer;
	int		m;

	if (n < 0)
		return (ft_Ifminus(n));
	if (n == 0)
		return (ft_IfZero());
	m = ft_LengthString(n);
	pointer = (char *)malloc(sizeof(char) * (m + 1));
	if (pointer == NULL)
		return (NULL);
	rez = pointer;
	pointer = pointer + m;
	*pointer-- = '\0';
	while (n != 0)
	{
		*pointer-- = (n % 10) + 48;
		n = n / 10;
	}
	return (rez);
}
