/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structstats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:48:11 by keverett          #+#    #+#             */
/*   Updated: 2019/09/02 10:48:15 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_structstats(t_n_list *lst)
{
	t_n_list *tmp;

	tmp = lst;
	while (lst)
	{
		if ((lstat(lst->name, &lst->sb)) == -1)
			tmp->error = 1;
		lst = lst->next;
	}
}
