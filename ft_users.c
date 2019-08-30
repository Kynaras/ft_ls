/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_users.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:05:33 by keverett          #+#    #+#             */
/*   Updated: 2019/08/28 17:05:35 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_users(t_f_list *flags, struct stat *sb, t_s_list *totals)
{
	int i;
	int numsize;

	if (flags->users == 0)
	{
		if (!getgrgid(sb->st_gid))
			numsize = ft_numcount(sb->st_gid);
		else
			numsize = ft_findlen(getgrgid(sb->st_gid)->gr_name);
		i = totals->gnamesize - numsize;
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
		if (!getgrgid(sb->st_gid))
			ft_putnbr(sb->st_gid);
		else
			ft_putstr((getgrgid(sb->st_gid)->gr_name));
		write(1, "  ", 2);
	}
}
