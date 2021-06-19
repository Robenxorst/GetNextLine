#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = malloc (size * count);
	if (pointer == NULL)
		return (NULL);
	while (i < count * size)
	{
		pointer[i] = 0;
		i++;
	}
	return (pointer);
}
