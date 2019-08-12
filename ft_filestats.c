/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filestats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:59:11 by keverett          #+#    #+#             */
/*   Updated: 2019/07/29 15:59:12 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_perms(struct stat sb, int i)
{
	if (i == 0 && S_ISDIR(sb.st_mode))
			ft_putchar('d');
	else if (i == 0 && S_ISLNK(sb.st_mode))
			ft_putchar('l');
	else if (i == 1 && S_IRUSR & sb.st_mode)
			ft_putchar('r');
	else if (i == 2 && S_IWUSR & sb.st_mode)
			ft_putchar('w');
	else if (i == 3 && S_IXUSR & sb.st_mode)
			ft_putchar('x');
	else if (i == 4 && S_IRGRP & sb.st_mode)
			ft_putchar('r');
	else if (i == 5 && S_IWGRP & sb.st_mode)
			ft_putchar('w');
	else if (i == 6 && S_IXGRP & sb.st_mode)
			ft_putchar('x');
	else if (i == 7 && S_IROTH & sb.st_mode)
			ft_putchar('r');
	else if (i == 8 && S_IWOTH & sb.st_mode)
			ft_putchar('w');
	else if (i == 9 && S_IXOTH & sb.st_mode)
			ft_putchar('x');
		else
			ft_putchar('-');
		return;
}
void ft_filestats(n_list *lst, struct stat sb)
{
	int i;
	size_t totsize;
	size_t numsize;

	i = 0;
	while (i < 10)
	{
		ft_perms(sb, i);
		i++;
	}
	ft_putchar(' ');
	totsize = ft_findsize(lst);
	numsize = ft_numsize(sb.st_nlink);
	i = totsize - numsize;
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr((int)sb.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(sb.st_uid)->pw_name);
	ft_putchar(' ');
	ft_putstr((getgrgid(sb.st_gid)->gr_name));
	ft_putchar(' ');
	ft_putlonglong(sb.st_size);
	//ft_putchar(' ');
	ft_timesplit(ctime(&sb.st_mtime));
	}