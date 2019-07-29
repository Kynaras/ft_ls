/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:47:59 by keverett          #+#    #+#             */
/*   Updated: 2019/06/28 12:29:43 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (src1[i] == src2[i])
		{
			i++;
		}
		else
			return (src1[i] - src2[i]);
	}
	return (0);
}
