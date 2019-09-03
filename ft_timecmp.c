/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:32:10 by keverett          #+#    #+#             */
/*   Updated: 2019/08/20 15:40:44 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ministr(t_n_list *a, t_n_list *b, t_n_list **result, t_f_list *flags)
{
	if (ft_strcmp((*a).name, (*b).name) <= 0)
	{
		(*result) = flags->reverse ? b : a;
		(*result)->next = flags->reverse ? sortlist(a, b->next, flags) :
		sortlist(a->next, b, flags);
	}
	else
	{
		*result = flags->reverse ? a : b;
		(*result)->next = flags->reverse ? sortlist(a->next, b, flags)
		: sortlist(a, b->next, flags);
	}
}

void	ft_timecmp(t_n_list *a, t_n_list *b, t_n_list **result, t_f_list *flags)
{
	struct stat ab;
	struct stat bb;

	lstat(a->path, &ab);
	lstat(b->path, &bb);
	if (ab.st_mtimespec.tv_sec > bb.st_mtimespec.tv_sec ||
	(ab.st_mtimespec.tv_sec == bb.st_mtimespec.tv_sec && ab.st_mtimespec.tv_nsec
	> bb.st_mtimespec.tv_nsec))
	{
		(*result) = flags->reverse ? b : a;
		(*result)->next = flags->reverse ? sortlist(a, b->next, flags) :
		sortlist(a->next, b, flags);
	}
	else if (ab.st_mtimespec.tv_sec == bb.st_mtimespec.tv_sec &&
	ab.st_mtimespec.tv_nsec == bb.st_mtimespec.tv_nsec)
		ft_ministr(a, b, result, flags);
	else
	{
		*result = flags->reverse ? a : b;
		(*result)->next = flags->reverse ? sortlist(a->next, b, flags) :
		sortlist(a, b->next, flags);
	}
}
