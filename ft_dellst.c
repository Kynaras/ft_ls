/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:47:21 by keverett          #+#    #+#             */
/*   Updated: 2019/07/30 13:47:24 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_dellst(t_n_list *lst)
{
	t_n_list *tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->name);
		free(lst->path);
		free(lst);
		lst = tmp;
	}
	return ;
}
