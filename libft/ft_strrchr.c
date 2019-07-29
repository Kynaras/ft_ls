/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:16:33 by keverett          #+#    #+#             */
/*   Updated: 2019/06/06 14:26:33 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c1;
	char	*str;

	str = (char*)s;
	c1 = (char)c;
	i = 0;
	while (str[i])
		i++;
	while (str[i] != c1 && i > 0)
		i--;
	if (str[i] == c1)
		return (str + i);
	return (NULL);
}
