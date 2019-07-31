/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:32:41 by keverett          #+#    #+#             */
/*   Updated: 2019/07/31 10:32:43 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

n_list *ft_readdir(char *path)
{
	DIR *dr = NULL;
	struct dirent *de;
	n_list *lst = NULL;
	
	dr = opendir(path);
    if (dr == NULL)
    {
        printf("Error: Could not open directory!\n");
        return (lst);
    }

	while ((de = readdir(dr)) != NULL)
    {
        if (ft_strncmp(de->d_name, ".", 1) != 0)
        {
         if (lst == NULL)
			lst = ls_lstnew(de->d_name);
         else
            ls_lstadd(lst, ls_lstnew(de->d_name));
        }
    }
    closedir(dr);
	return(lst);
}