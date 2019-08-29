/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:46:24 by keverett          #+#    #+#             */
/*   Updated: 2019/07/23 11:46:28 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <sys/errno.h>
#include "ft_ls.h"
#include <stdlib.h>
#include "libft/libft.h"

void	splitlist(t_n_list *original, t_n_list **first, t_n_list **second)
{
	t_n_list *count;
	t_n_list *count2;

	count = original->next;
	count2 = original;
	while (count != NULL)
	{
		count = count->next;
		if (count != NULL)
		{
			count2 = count2->next;
			count = count->next;
		}
	}
	*first = original;
	*second = count2->next;
	count2->next = NULL;
}

void	ft_mergesort(t_n_list **lst, t_f_list *flags)
{
	t_n_list *head;
	t_n_list *a;
	t_n_list *b;

	a = NULL;
	b = NULL;
	head = *lst;
	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	splitlist(head, &a, &b);
	ft_mergesort(&a, flags);
	ft_mergesort(&b, flags);
	*lst = sortlist(a, b, flags);
}
