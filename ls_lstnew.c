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

t_n_list *ls_lstnew(char *str, char *path)
{
	t_n_list *new;

	new = malloc(sizeof(t_n_list));
	if (new == NULL)
		return (NULL);
	new->name = ft_strdup(str);
	new->path = ft_strdup(path);
	new->last = new;
	new->error = 0;
	if (ft_strcmp(path, "/"))
		ft_join(&new->path, "/");
	ft_join(&new->path, str);
	new->next = NULL;
	return (new);
}