/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:58:24 by keverett          #+#    #+#             */
/*   Updated: 2019/06/06 14:24:57 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (i + g + 1 < dstsize && src[g])
	{
		dst[i + g] = src[g];
		g++;
	}
	if (i < dstsize)
		dst[i + g] = '\0';
	return (ft_strlen(src) + i);
}
