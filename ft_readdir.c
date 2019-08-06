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

n_list *ft_readdir(char *path, f_list flags)
{
	DIR *dr;
	struct dirent *de;
	n_list *lst;
    n_list *dirs;
    char *str;
	
    dirs = NULL;
    dr = NULL;
    lst = NULL;
	if(!(dr = opendir(path)))
    {
        perror("Error: ");
        return (lst);
    }
	while ((de = readdir(dr)) != NULL)
    {
         if (lst == NULL)
			lst = ls_lstnew(de->d_name);
         else
            ls_lstadd(lst, ls_lstnew(de->d_name));
        if (de->d_type == DT_DIR && ft_strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0 )
        {
            if (dirs == NULL)
               dirs = ls_lstnew(de->d_name);
            else
                ls_lstadd(dirs, ls_lstnew(de->d_name));
        }
    }
    ft_mergesort(&lst);
    ft_printlst(lst, flags);
    ft_dellst(lst);
    closedir(dr);

    if (flags.recursive == 1)
    {
        while (dirs != NULL)
    {
        str = ft_strdup(path);
        ft_join(&str, "/");
        ft_join(&str, (*dirs).name);
        ft_putchar('\n');
        ft_putstr(str);
        ft_putstr(":\n");
        ft_readdir(str, flags);
        free(str);
        dirs = dirs->next;
    }
    }
	return(dirs);
}