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

size_t ft_findsize(n_list *lst, int type)
{
	size_t size;
	size_t num;
	size_t i;
	
	num = 0;
	i = 0;
	size = 1;

	while (lst)
	{
		if (type == 1)
		{
			if(lst->sb.st_blocks > num)
				num = lst->sb.st_blocks;
		}
		else if (type == 2)
		{
			if (lst->sb.st_size > num)
				num = lst->sb.st_size;
		}
		lst = lst->next;
	}

	while (num)
	{
		num /= 10;
		i++;
	}	
	i = i == 0 ? 1 : i;
	return (i);
}
