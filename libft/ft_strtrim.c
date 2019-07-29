/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 07:17:10 by keverett          #+#    #+#             */
/*   Updated: 2019/06/06 14:39:25 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*st_string(char *str, size_t n)
{
	char *str2;

	str2 = ft_memalloc(n * sizeof(char) + 1);
	if (str2 == NULL)
		return (NULL);
	else
		return (ft_strcpy(str2, str));
}

static char	*st_stringn(char *str, size_t n)
{
	char *str3;

	str3 = ft_memalloc(n * sizeof(char) + 1);
	if (str3 == NULL)
		return (NULL);
	else
		return (ft_strncpy(str3, str, n));
}

char		*ft_strtrim(char const *s)
{
	size_t i;
	size_t begin;
	size_t end;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		return (st_string("", 1));
	}
	begin = i;
	while (s[i])
		i++;
	i -= 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	end = i;
	return (st_stringn((char*)(s + begin), end - begin + 1));
}
