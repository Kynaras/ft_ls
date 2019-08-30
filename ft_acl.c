/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ACL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:50:49 by keverett          #+#    #+#             */
/*   Updated: 2019/08/30 11:50:50 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_acl(char *path)
{
	acl_t acl;

	if (ft_attr(path) > 0)
		ft_putchar('@');
	else if ((acl = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		ft_putchar('+');
		acl_free(acl);
	}
	else
		(ft_putchar(' '));
}
