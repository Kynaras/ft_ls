/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:32:10 by keverett          #+#    #+#             */
/*   Updated: 2019/08/09 13:32:12 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_timecmp(n_list *a, n_list *b, n_list **result, f_list flags)
{
    struct stat ab;
    struct stat bb;

    lstat(a->path, &ab);
    lstat(b->path, &bb);

    if (ab.st_mtime >= bb.st_mtime)
	{
		(*result) = flags.reverse ? b : a;
		(*result)->next = flags.reverse ? sortlist(b->next, a, flags) : sortlist (a->next, b, flags);
	}
	else
	{
		*result = flags.reverse ? a : b;
		(*result)->next = flags.reverse ? sortlist(b, a->next, flags) : sortlist(a, b->next, flags);
	}
}
