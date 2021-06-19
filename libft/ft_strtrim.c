#include "libft.h"

static char	*ft_BadSize(int n)
{
	char	*rez;

	rez = (char *) malloc(sizeof(char));
	if ((!rez) && (n < 0))
		return (NULL);
	rez[0] = '\0';
	return (rez);
}

static int	ft_foundCharIn(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_begin(char const *s1, char const *set)
{
	int	rez;
	int	i;

	rez = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_foundCharIn(s1[i], set) == 1)
			rez++;
		else
			break ;
		i++;
	}
	return (rez);
}

static int	ft_end(char const *s1, char const *set)
{
	int	rez;
	int	i;

	rez = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	while (i != 0)
	{
		if (ft_foundCharIn(s1[i], set) == 1)
			rez++;
		else
			break ;
		i--;
	}
	return (rez);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	char	*pointer;
	int		n;

	if (s1 == 0)
		return (NULL);
	n = 0;
	while (s1[n] != '\0')
		n++;
	n = n - ft_end(s1, set) - ft_begin(s1, set);
	if ((n < 0) || *s1 == '\0')
		return (ft_BadSize(n));
	pointer = (char *)malloc(sizeof(char const) * (n + 1));
	if (pointer == NULL)
		return (NULL);
	r = pointer;
	s1 = s1 + ft_begin(s1, set);
	while (n != 0)
	{
		*pointer++ = *s1++;
		n--;
	}
	*pointer = '\0';
	return (r);
}
