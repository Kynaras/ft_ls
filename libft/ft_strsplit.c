/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:55:38 by keverett          #+#    #+#             */
/*   Updated: 2019/06/12 16:29:53 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			st_count(char const *s, char c)
{
	size_t i;
	size_t d;
	size_t strings;

	i = 0;
	d = 1;
	strings = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && d == 1)
		{
			d = 0;
			strings++;
		}
		if (s[i] == c && d == 0)
			d = 1;
		i++;
	}
	return (strings);
}

static char	const	*st_findstring(char const *s, char c, size_t w)
{
	size_t i;
	size_t d;
	size_t strings;

	i = 0;
	d = 1;
	strings = -1;
	while (s[i] != '\0')
	{
		if (s[i] != c && d == 1)
		{
			d = 0;
			strings++;
		}
		if (s[i] == c && d == 0)
			d = 1;
		if (strings == w)
			return ((s + i));
		i++;
	}
	return (NULL);
}

static size_t		st_strlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void			st_alloc(char const *s, char **arr, char c, size_t index)
{
	size_t j;

	j = 0;
	while (s[j])
	{
		if (s[j] == c)
			break ;
		arr[index][j] = s[j];
		j++;
	}
	arr[index][j] = '\0';
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**arr;

	if (s == NULL)
		return (NULL);
	size = st_count(s, c);
	i = 0;
	arr = (char**)malloc(st_count(s, c) * sizeof(char *) + 1);
	if (arr == NULL)
		return (NULL);
	while (i < size)
	{
		arr[i] = (char*)malloc(st_strlen(st_findstring(s, c, i), c) *
				sizeof(char) + 1);
		if (arr[i] == NULL)
			return (NULL);
		st_alloc(st_findstring(s, c, i), arr, c, i);
		i++;
	}
	arr[i] = (NULL);
	return (arr);
}
