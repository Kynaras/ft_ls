/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:44:22 by keverett          #+#    #+#             */
/*   Updated: 2019/07/10 14:21:42 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c1;

	c1 = (char)c;
	i = 0;
	while (s[i] && s[i] != c1)
	{
		i++;
	}
	if (s[i] == c1)
		return ((char*)s + i);
	else
		return (NULL);
}
