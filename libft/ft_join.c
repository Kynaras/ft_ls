/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:39:39 by keverett          #+#    #+#             */
/*   Updated: 2019/08/15 17:07:10 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_join(char **line, char *buf)
{
	char *temp;

	if (*line == NULL)
		*line = ft_memalloc(1);
	temp = ft_strjoin(*line, buf);
	free(*line);
	*line = temp;
}
