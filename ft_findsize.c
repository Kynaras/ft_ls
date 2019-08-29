/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:00:44 by keverett          #+#    #+#             */
/*   Updated: 2019/08/12 17:02:12 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ft_findsize(t_n_list *lst, int type)
{
	long long	num;
	size_t		i;

	num = 0;
	i = 0;
	while (lst)
	{
		if (type == 1 && lst->sb.st_nlink > num)
			num = lst->sb.st_nlink;
		else if (type == 2 && lst->sb.st_size > num)
			num = lst->sb.st_size;
		lst = lst->next;
	}
	while (num)
	{
		num /= 10;
		i++;
	}
	i = i == 0 ? 1 : i;
	return (i + 1);
}
