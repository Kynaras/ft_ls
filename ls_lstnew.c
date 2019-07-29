/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:07:02 by keverett          #+#    #+#             */
/*   Updated: 2019/07/22 14:07:07 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stddef.h>
#include <stdlib.h>

n_list *ls_lstnew(struct dirent *pt)
{
	n_list *new;

	new = malloc(sizeof(n_list));
	if (new == NULL)
		return (NULL);
	new->ptr = pt;
	new->next = NULL;
	return (new);
}