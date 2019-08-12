/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structstat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:20:12 by keverett          #+#    #+#             */
/*   Updated: 2019/08/12 16:20:14 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_structstat(n_list *lst)
{
	struct stat sb;
	while (lst)
	{
		lstat(lst->path, &lst->sb);
		lst = lst->next;	
	}
}
