/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:29:41 by keverett          #+#    #+#             */
/*   Updated: 2019/08/02 16:29:45 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void 	ft_errorcheck(char *str, n_list **lst, n_list **dirs)
{
	DIR *dr;

	if(!(dr = opendir(str)))
		{
			if (errno == ENOTDIR)
			{
				if (lst == NULL)
					*lst = ls_lstnew(str, ".");
				else
					ls_lstadd(*lst, ls_lstnew(str, "."));
			}
			else if (errno == ENOENT)
				perror("Error ");			
		}
	else
	{
		if (dirs == NULL)
			*dirs = ls_lstnew(str,".");
		else
			ls_lstadd(*dirs, ls_lstnew(str, "."));
	}
}