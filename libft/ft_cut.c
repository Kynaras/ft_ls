/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:15:00 by keverett          #+#    #+#             */
/*   Updated: 2019/06/28 16:58:45 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut(char **str, char c)
{
	int		i;
	char	*new;
	char	**arr;

	new = NULL;
	arr = ft_strsplit(*str, c);
	i = 0;
	if (*str == NULL)
		return (NULL);
	while (arr[i] != NULL)
	{
		ft_join(&new, arr[i]);
		i++;
	}
	return (new);
}
