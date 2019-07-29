/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 04:43:39 by keverett          #+#    #+#             */
/*   Updated: 2019/07/06 04:44:19 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *s1, int c)
{
	char	*str;
	size_t	i;

    i = 0;
    if(s1)
    {
        while (i < ft_strlen(s1))
        {
            if(s1[i] == c)
            {
                str = ft_strnew(i);
                i = 0;
                while(s1[i] != c)
                {
                    str[i] = s1[i];
                    i++;
                }
                return str;
            }
            i++;
        }
    }
    return (NULL);
}
