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

void	ft_timecmp(t_n_list *a, t_n_list *b, t_n_list **result, t_f_list *flags)
{
	struct stat ab;
	struct stat bb;

	lstat(a->path, &ab);
	lstat(b->path, &bb);
	if (ab.st_mtime > bb.st_mtime || (ab.st_mtimespec.tv_sec >
	bb.st_mtimespec.tv_sec && ab.st_mtime == bb.st_mtime) ||
	(ab.st_mtimespec.tv_nsec >= bb.st_mtimespec.tv_nsec &&
	ab.st_mtimespec.tv_sec == bb.st_mtimespec.tv_sec && ab.st_mtime ==
	bb.st_mtime))
	{
		(*result) = flags->reverse ? b : a;
		(*result)->next = flags->reverse ? sortlist(b->next, a, flags) :
		sortlist(a->next, b, flags);
	}
	else
	{
		*result = flags->reverse ? a : b;
		(*result)->next = flags->reverse ? sortlist(b, a->next, flags) :
		sortlist(a, b->next, flags);
	}
}
