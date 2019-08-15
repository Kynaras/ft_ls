/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:43:01 by keverett          #+#    #+#             */
/*   Updated: 2019/08/15 16:43:02 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_attr(char *path)
{
	char *buf;
	int i;
	
	buf = NULL;
	i = listxattr(path, buf, 1, XATTR_NOFOLLOW);
	return (i);
}