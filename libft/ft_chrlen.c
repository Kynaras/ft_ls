#include "libft.h"

ssize_t	ft_chrlen(char *buf, char c)
{
	int i;

	i = 0;
	if (buf[0] == '\0')
		return (-1);
	while (buf[i])
	{
		if (buf[0] == c)
			return (0);
		if (buf[i] == c)
			return (i);
		i++;
	}
	return (i);
}

