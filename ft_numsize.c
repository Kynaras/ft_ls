/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:13:52 by keverett          #+#    #+#             */
/*   Updated: 2019/08/12 17:13:53 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ft_numsize(long long number)
{
	size_t num;
	size_t i;

	i = 0;
	if (number == 0)
		return (1);
	num = number;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}
