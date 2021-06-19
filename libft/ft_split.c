#include "libft.h"

static size_t	ft_KolWord(const char *s, char c)
{
	size_t	rez;

	rez = 0;
	while (*s)
	{
		while ((*s == c) && *s)
			s++;
		if (*s && (*s != c))
			rez++;
		while (*s && (*s != c))
			s++;
	}
	return (rez);
}

static size_t	LenSymbol(char const *s, char c)
{
	size_t	rez;

	rez = 0;
	while ((*s != c) && *s)
	{
		s++;
		rez++;
	}
	return (rez);
}

static void	AllFree(char **res, char **res_start)
{
	while (res != res_start)
	{
		free (*res);
		res--;
	}
	free (*res);
	free (res);
}

static char	**MiniSplit(char **res, const char *s, char c)
{
	char	**point;
	size_t	lensubstr;

	point = res;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			lensubstr = LenSymbol (s, c);
			*res = malloc(sizeof(**res) * (lensubstr + 1));
			if (*res == NULL)
			{
				AllFree(res, point);
				return (NULL);
			}
			ft_strlcpy(*res, s, (lensubstr + 1));
			s = s + lensubstr;
			res++;
		}
	}
	*res = NULL;
	return (point);
}

char	**ft_split(char const *s, char c)
{
	char	**rez;
	size_t	Kolword;

	if (s == 0)
		return (NULL);
	Kolword = ft_KolWord(s, c);
	rez = (char **)malloc(sizeof(*rez) * (Kolword + 1));
	if (rez == NULL)
		return (NULL);
	rez = MiniSplit (rez, s, c);
	return (rez);
}
