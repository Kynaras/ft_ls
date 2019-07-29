/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 06:59:52 by keverett          #+#    #+#             */
/*   Updated: 2019/06/28 11:16:20 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_malloc(int n)
{
	int size;
	int rem;

	rem = 0;
	size = 0;
	if (n < 0)
	{
		size++;
		n = n * -1;
	}
	if (n == 0)
		size++;
	while (n != 0)
	{
		rem = n % 10;
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*st_string(char *str, int size, int n)
{
	int rem;

	rem = 0;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		rem = n % 10;
		str[size] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		rem;
	int		size;
	char	*str;

	if (n == -2147483648)
	{
		str = ft_memalloc(12 * sizeof(char));
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	size = st_malloc(n);
	str = ft_strnew(size);
	rem = 0;
	if (str == NULL)
		return (NULL);
	size--;
	str = st_string(str, size, n);
	return (str);
}
