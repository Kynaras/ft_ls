/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:23:48 by keverett          #+#    #+#             */
/*   Updated: 2019/08/13 17:23:50 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_linkname(char *path)
{
	char	*buf;
	size_t	len;
	size_t	size;

	len = 1024;
	size = 1024;
	while (size == len)
	{
		buf = ft_memalloc(len);
		size = readlink(path, buf, len);
		free(buf);
		len += size;
		size += size;
	}
	len = size + 1;
	buf = ft_memalloc(len);
	readlink(path, buf, len);
	buf[len - 1] = '\0';
	ft_putstr(buf);
	free(buf);
}
