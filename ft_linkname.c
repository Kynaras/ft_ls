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

char *ft_linkname(char *path)
{
	char *buf;
	size_t len;

	len = readlink(path, buf, 0);
	buf = ft_memalloc(len + 1);
	ft_bzero(buf, len + 1);
	readlink(path, buf, len);
	return (buf);
}