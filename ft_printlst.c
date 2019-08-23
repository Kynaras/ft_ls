/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:15:38 by keverett          #+#    #+#             */
/*   Updated: 2019/07/31 09:15:42 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_regfiles(n_list *lst, f_list flags, s_list totals)
{
    if (*lst->name != '.')
        {
            if (flags.list == 1)
             {
                 ft_filestats(lst->sb, lst->path, totals);
                 ft_putchar(' ');
             }
            ft_putstr(lst->name);
            if (S_ISLNK(lst->sb.st_mode))
             {
                 ft_putstr(" -> ");
                 ft_linkname(lst->path);
             }
            ft_putchar('\n');
        }    
}

void    ft_hiddenfiles(n_list *lst, f_list flags, s_list totals)
{
    if (flags.list == 1)
             {
                 ft_filestats(lst->sb, lst->path, totals);
                 ft_putchar(' ');
             }
             ft_putstr(lst->name);
             if (S_ISLNK(lst->sb.st_mode))
             {
                 ft_putstr(" -> ");
                 ft_linkname(lst->path);
             }
             ft_putchar('\n');
}
void    ft_totalsize(n_list *lst)
{
    long long size;
	
    size = 0;
    while (lst)
    { 
        size += lst->sb.st_blocks;
        lst = lst->next;
    }
    ft_putstr("total ");
    ft_putlonglong(size);
    ft_putchar('\n');
}

void ft_printlst(n_list *lst, f_list flags)
{
    s_list totals;

    if (flags.list == 1 && lst != NULL)
    {
        ft_structstat(lst);
        totals = ft_totalsizelst(lst);
        ft_totalsize(lst);
    }
	while (lst != NULL)
    {   
        if (*lst->name == '.' && flags.hidden == 1) 
            ft_hiddenfiles(lst, flags, totals);
        else if (*lst->name != '.')
            ft_regfiles(lst, flags, totals);
        lst = lst->next;
    }
	return ;
}