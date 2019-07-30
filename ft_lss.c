/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:06:13 by keverett          #+#    #+#             */
/*   Updated: 2019/07/30 12:06:17 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_lss(char *path)
{   
	DIR *dr = NULL;
	struct dirent *de;
	n_list *lst = NULL;

    dr = opendir(path);
    if (dr == NULL)
    {
        printf("Error: Could not open directory!\n", path);
        return (NULL);
    }

	while ((de = readdir(dr)) != NULL)
    {
        if (lst == NULL)
        {
			lst = ls_lstnew(de->d_name);
        }
        else
        {
            ls_lstadd(lst, ls_lstnew(de->d_name));
        }
    }
	ft_mergesort(&lst);

    while (lst != NULL)
    {
        printf("%s\n", lst->name);
        lst = lst->next;
    }
    closedir(dr);
    return;
}
