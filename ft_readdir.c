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
	v_list vars;
	
    vars.tmp = NULL;
    vars.dirs = NULL;
    vars.dr = NULL;
    vars.lst = NULL;

	if(!(vars.dr = opendir(path)))
    {
        if (errno == EACCES || errno == ENOENT)
            {
                ft_putstr("ft_ls: ");
                ft_putstr(path);
                perror(" ");
            }
        else if (errno == ENOTDIR)
        {
            if(flags.list == 1)
            {
                vars.lst = ls_lstnew(path, NULL);
                vars.lst->path = ft_strdup(path);
                ft_structstat(vars.lst);
                ft_filestats(vars.lst, vars.lst->sb, vars.lst->path);
                ft_putchar(' ');
            }
            ft_putstr(vars.lst->path);
            ft_putchar('\n');
        }
        return (vars.lst);
    }
	while ((vars.de = readdir(vars.dr)) != NULL)
    {
        if (vars.lst == NULL)
            vars.lst = ls_lstnew(vars.de->d_name, path);
        else if (vars.lst != NULL)
            ls_lstadd(vars.lst, ls_lstnew(vars.de->d_name, path));
        if (vars.de->d_type == DT_DIR && ft_strcmp(vars.de->d_name, ".") != 0 && ft_strcmp(vars.de->d_name, "..") != 0 )
        {
            if (vars.dirs == NULL)
               vars.dirs = ls_lstnew(vars.de->d_name, path);
            else
                ls_lstadd(vars.dirs, ls_lstnew(vars.de->d_name, path));
        }
    }

    ft_mergesort(&vars.dirs, flags);
    ft_mergesort(&vars.lst, flags);
    ft_printlst(vars.lst, flags);
    ft_dellst(vars.lst);
    closedir(vars.dr);
  
    vars.tmp = vars.dirs;
    if (flags.recursive == 1)
    {
        while (vars.dirs != NULL)
    {
        if (*vars.dirs->name != '.' || (flags.hidden == 1 && *vars.dirs->name == '.'))
        {
            
            ft_putchar('\n');
            ft_putstr(vars.dirs->name);
            ft_putstr(":\n");
            vars.lst = ft_readdir(vars.dirs->path, flags);
            ft_dellst(vars.lst);
        }
        vars.dirs = vars.dirs->next;
        }
    }
	return(vars.tmp);
}