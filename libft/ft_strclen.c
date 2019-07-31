/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 23:18:36 by keverett          #+#    #+#             */
/*   Updated: 2019/07/05 23:37:50 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char *str, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;

	while (str[i] != '\0')
	{
		if (str[i] != c)
			j++;
		if (str[i] == c)
			return (j);
		i++;
	}
	return (0);
}