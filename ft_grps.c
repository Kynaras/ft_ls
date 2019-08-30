/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:59:53 by keverett          #+#    #+#             */
/*   Updated: 2019/08/28 17:00:19 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_grps(t_f_list *flags, struct stat *sb, t_s_list *totals)
{
	int numsize;
	int i;

	if (flags->groups == 0)
	{
		if (!getpwuid(sb->st_uid))
			numsize = ft_numcount(sb->st_uid);
		else
			numsize = ft_findlen(getpwuid(sb->st_uid)->pw_name);
		i = totals->unamesize - numsize;
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		if (!getpwuid(sb->st_uid))
			ft_putnbr(sb->st_uid);
		else
			ft_putstr(getpwuid(sb->st_uid)->pw_name);
		write(1, "  ", 2);
	}
}
