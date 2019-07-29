/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 07:45:17 by keverett          #+#    #+#             */
/*   Updated: 2019/06/06 14:34:55 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*n;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(n = (char*)malloc(ft_strlen(s) * sizeof(char) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		n[i] = f(i, s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
