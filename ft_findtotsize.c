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
	struct passwd *name = NULL;
	struct group *gname = NULL;
	num = 0;
	while(lst)
	{
		if(type == 1 && (name = getpwuid(lst->sb.st_uid)) && ft_findlen(name->pw_name) > num)
			num = ft_findlen(getpwuid(lst->sb.st_uid)->pw_name);
		else if (type == 1 && !(getpwuid(lst->sb.st_uid)) && ft_numcount(lst->sb.st_uid) > num)
			num = ft_numcount(lst->sb.st_uid);
		else if (type == 2 && (gname = getgrgid(lst->sb.st_gid)) && ft_findlen(gname->gr_name) > num)
			num = ft_findlen(gname->gr_name);
		else if (type == 2 && !(getgrgid(lst->sb.st_gid)) && ft_numcount(lst->sb.st_uid) > num)
			num = ft_numcount(lst->sb.st_gid);
		lst = lst->next;
	}
	return num;
}
