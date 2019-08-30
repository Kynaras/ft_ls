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

void	ft_user(struct stat sb, int i)
{
	if (i == 1)
		S_IRUSR & sb.st_mode ? ft_putchar('r') : ft_putchar('-');
	else if (i == 2)
		S_IWUSR & sb.st_mode ? ft_putchar('w') : ft_putchar('-');
	else if (i == 3)
	{
		if (S_IXUSR & sb.st_mode)
			S_ISUID & sb.st_mode ? ft_putchar('s') : ft_putchar('x');
		else if (!(S_IXUSR & sb.st_mode))
			S_ISUID & sb.st_mode ? ft_putchar('S') : ft_putchar('-');
	}
}

void	ft_group(struct stat sb, int i)
{
	if (i == 4)
		S_IRGRP & sb.st_mode ? ft_putchar('r') : ft_putchar('-');
	else if (i == 5)
		S_IWGRP & sb.st_mode ? ft_putchar('w') : ft_putchar('-');
	else if (i == 6)
	{
		if (S_IXGRP & sb.st_mode)
			S_ISGID & sb.st_mode ? ft_putchar('s') : ft_putchar('x');
		else if (!(S_IXGRP & sb.st_mode))
			S_ISGID & sb.st_mode ? ft_putchar('S') : ft_putchar('-');
	}
}

void	ft_others(struct stat sb, int i)
{
	if (i == 7)
		S_IROTH & sb.st_mode ? ft_putchar('r') : ft_putchar('-');
	else if (i == 8)
		S_IWOTH & sb.st_mode ? ft_putchar('w') : ft_putchar('-');
	else if (i == 9)
	{
		if (S_IXOTH & sb.st_mode)
			S_ISVTX & sb.st_mode ? ft_putchar('t') : ft_putchar('x');
		else
			S_ISVTX & sb.st_mode ? ft_putchar('T') : ft_putchar('-');
	}
}

void	ft_perms(struct stat sb, int i)
{
	if (i == 0)
	{
		if (S_ISDIR(sb.st_mode))
			ft_putchar('d');
		else if (S_ISLNK(sb.st_mode))
			ft_putchar('l');
		else if (S_ISFIFO(sb.st_mode))
			ft_putchar('p');
		else if (S_ISSOCK(sb.st_mode))
			ft_putchar('s');
		else if (S_ISCHR(sb.st_mode))
			ft_putchar('c');
		else if (S_ISBLK(sb.st_mode))
			ft_putchar('b');
		else
			ft_putchar('-');
	}
	else if (i >= 1 && i <= 3)
		ft_user(sb, i);
	else if (i >= 4 && i <= 6)
		ft_group(sb, i);
	else if (i >= 7 && i <= 9)
		ft_others(sb, i);
	return ;
}

void	ft_filestats(struct stat sb, char *path, t_s_list totals,
t_f_list *flags)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		ft_perms(sb, i);
		i++;
	}
	ft_acl(path);
	i = totals.linksize - ft_numsize(sb.st_nlink);
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr((int)sb.st_nlink);
	ft_putchar(' ');
	ft_grps(flags, &sb, &totals);
	ft_users(flags, &sb, &totals);
	ft_size(&sb, &totals);
	ft_putlonglong(sb.st_size);
	ft_timesplit(ctime(&sb.st_mtimespec.tv_sec), &sb);
}
