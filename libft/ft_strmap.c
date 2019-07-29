/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:43:39 by keverett          #+#    #+#             */
/*   Updated: 2019/06/05 15:14:34 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*n;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(n = (char*)malloc(ft_strlen(s) * sizeof(char) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		n[i] = f(s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
