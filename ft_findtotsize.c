/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtotsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:18:15 by keverett          #+#    #+#             */
/*   Updated: 2019/08/13 08:18:16 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t ft_findtotsize(n_list *lst, int type)
{
	size_t num;

	num = 0;
	while(lst)
	{
		if(type == 1 && ft_findlen(getpwuid(lst->sb.st_uid)->pw_name) > num)
			num = ft_findlen(getpwuid(lst->sb.st_uid)->pw_name);
		else if (type == 2 && ft_findlen(getgrgid(lst->sb.st_gid)->gr_name) > num)
			num = ft_findlen(getgrgid(lst->sb.st_gid)->gr_name);
		lst = lst->next;
	}
	return num;
}
