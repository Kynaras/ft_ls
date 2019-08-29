/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:30:19 by keverett          #+#    #+#             */
/*   Updated: 2019/08/29 13:30:23 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_colours(t_n_list *lst)
{
	if (S_ISDIR(lst->sb.st_mode))
	{
		if (S_IWOTH & lst->sb.st_mode)
			S_ISVTX & lst->sb.st_mode ? ft_putstr("\033[30;48;2;20;190;130m")
			: ft_putstr("\033[30;43m");
		else
			ft_putstr("\033[34m");
	}
	else if (S_ISREG(lst->sb.st_mode) && (S_IXOTH & lst->sb.st_mode ||
	S_IXGRP & lst->sb.st_mode || S_IXUSR & lst->sb.st_mode))
	{
		if (S_ISVTX & lst->sb.st_mode)
			ft_putstr("\033[30;48;2;194;54;33m");
		else if (S_ISGID & lst->sb.st_mode)
			ft_putstr("\033[34;104m");
		else
			ft_putstr("\033[31m");
	}
	else if (S_ISLNK(lst->sb.st_mode))
		ft_putstr("\033[35m");
	else if (S_ISCHR(lst->sb.st_mode))
		ft_putstr("\033[34;103m");
	else if (S_ISBLK(lst->sb.st_mode))
		ft_putstr("\033[34;104m");
	ft_putstr(lst->name);
}
