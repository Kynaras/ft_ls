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

void	splitlist(n_list *original, n_list **first, n_list **second)
{
	n_list *count = NULL;
	n_list *count2 = NULL;

	count = original->next;
	count2 = original;

	while (count != NULL)
	{
		count = count->next;
		if(count != NULL)
		{
			count2 = count2->next;
			count = count->next;
		}
	}
	*first = original;
	*second = count2->next;
	count2->next = NULL;
}

void	ft_mergesort(n_list **lst, f_list flags)
{
	n_list *head = *lst;
	n_list *a = NULL;
	n_list *b = NULL;

	if (*lst == NULL || (*lst)->next == NULL)
	{
		return ;
	}

	splitlist(head, &a, &b);
	ft_mergesort(&a, flags);
	ft_mergesort(&b, flags);
	*lst = sortlist(a, b, flags);
}