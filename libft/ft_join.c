/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:39:39 by keverett          #+#    #+#             */
/*   Updated: 2019/07/05 17:19:18 by keverett         ###   ########.fr       */
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
	*line = ft_strdup(temp);
	free(temp);
}
