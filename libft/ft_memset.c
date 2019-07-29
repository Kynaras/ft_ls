/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:40:47 by keverett          #+#    #+#             */
/*   Updated: 2019/05/28 11:37:39 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	a;

	i = 0;
	str = (unsigned char*)b;
	a = (unsigned char)c;
	while (i < len)
	{
		str[i] = a;
		i++;
	}
	return (b);
}
