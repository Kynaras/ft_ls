/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:15:38 by keverett          #+#    #+#             */
/*   Updated: 2019/07/31 09:15:42 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_regfiles(t_n_list *lst, t_f_list *flags, t_s_list totals)
{
	if (*lst->name != '.')
	{
		if (flags->list == 1)
		{
			ft_filestats(lst->sb, lst->path, totals, flags);
			ft_putchar(' ');
		}
		if (flags->colours == 1)
		{
			ft_colours(lst);
			ft_putstr("\033[0m");
		}
		else
			ft_putstr(lst->name);
		if (S_ISLNK(lst->sb.st_mode))
		{
			ft_putstr(" -> ");
			ft_linkname(lst->path);
		}
		ft_putchar('\n');
	}
}

void	ft_hiddenfiles(t_n_list *lst, t_f_list *flags, t_s_list totals)
{
	if (flags->list == 1)
	{
		ft_filestats(lst->sb, lst->path, totals, flags);
		ft_putchar(' ');
	}
	if (flags->colours == 1)
	{
		ft_colours(lst);
		ft_putstr("\033[0m");
	}
	else
		ft_putstr(lst->name);
	if (S_ISLNK(lst->sb.st_mode))
	{
		ft_putstr(" -> ");
		ft_linkname(lst->path);
	}
	ft_putchar('\n');
}

void	ft_semihiddenfiles(t_n_list *lst, t_f_list *flags, t_s_list totals)
{
	if (flags->list == 1 && ft_strcmp(lst->name, ".") != 0 &&
		ft_strcmp(lst->name, "..") != 0)
	{
		ft_filestats(lst->sb, lst->path, totals, flags);
		ft_putchar(' ');
		if (flags->colours == 1)
		{
			ft_colours(lst);
			ft_putstr("\033[0m");
		}
		else
			ft_putstr(lst->name);
	}
	if (S_ISLNK(lst->sb.st_mode))
	{
		ft_putstr(" -> ");
		ft_linkname(lst->path);
	}
	ft_putchar('\n');
}

void	ft_totalsize(t_n_list *lst, t_f_list *flags)
{
	long long size;

	size = 0;
	while (lst)
	{
		if (*lst->name != '.' || (flags->hidden == 1 && *lst->name == '.') ||
			(flags->unsorted == 1 & *lst->name == '.'))
			size += lst->sb.st_blocks;
		lst = lst->next;
	}
	ft_putstr("total ");
	ft_putlonglong(size);
	ft_putchar('\n');
}

void	ft_printlst(t_n_list *lst, t_f_list *flags)
{
	t_s_list totals;

	if ((flags->list == 1 || flags->colours == 1) && lst != NULL)
	{
		ft_structstat(lst);
		if (lst->error == 1)
			return ;
		if (flags->list == 1)
		{
			totals = ft_totalsizelst(lst);
			ft_totalsize(lst, flags);
		}
	}
	while (lst != NULL)
	{
		if (*lst->name == '.' && (flags->hidden == 1 || flags->unsorted == 1))
			ft_hiddenfiles(lst, flags, totals);
		else if (*lst->name == '.' && flags->semihidden == 1)
			ft_semihiddenfiles(lst, flags, totals);
		else
			ft_regfiles(lst, flags, totals);
		lst = lst->next;
	}
	return ;
}
