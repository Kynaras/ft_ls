/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:11:51 by keverett          #+#    #+#             */
/*   Updated: 2019/06/28 12:33:16 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numcount(long int n)
{
	int			size;
	long int	rem;

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
