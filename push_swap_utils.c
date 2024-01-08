#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int     char_exists(const char *str, int c)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	i = 0;
	while (i <= size)
	{
		if (str[i] == (char)c)
			return 1;
		i++;
	}
	return (0);
}
