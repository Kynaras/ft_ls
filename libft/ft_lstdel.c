/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:12:19 by keverett          #+#    #+#             */
/*   Updated: 2019/06/06 15:13:00 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *holder;

	if (alst != NULL && del != NULL)
	{
		current = *alst;
		holder = *alst;
		while (holder != NULL)
		{
			current = current->next;
			del(holder->content, holder->content_size);
			free(holder);
			holder = current;
		}
		*alst = NULL;
	}
}
