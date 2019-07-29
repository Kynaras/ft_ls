/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:11:16 by keverett          #+#    #+#             */
/*   Updated: 2019/06/11 14:35:11 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstaddr(t_list **alst, t_list *newa)
{
	if (alst != NULL)
	{
		(*newa).next = NULL;
		(**alst).next = newa;
	}
	return (newa);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *current;
	t_list *new;
	t_list *tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	current = lst->next;
	new = f(lst);
	tmp = new;
	if (new == NULL || tmp == NULL)
		return (NULL);
	while (current != NULL)
	{
		if (f(current) == NULL)
			return (NULL);
		tmp = ft_lstaddr(&tmp, f(current));
		current = current->next;
	}
	return (new);
}
