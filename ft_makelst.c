/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:50:52 by keverett          #+#    #+#             */
/*   Updated: 2019/07/29 13:50:54 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>
#include "libft/libft.h"

n_list	*ft_makelst(DIR *dr, f_list flags)
{
	n_list *lst = NULL;
    struct dirent *de = NULL;
    n_list *dirs = NULL;

	while ((de = readdir(dr)) != NULL)
    {
        if (de->d_type == DT_DIR)
        {
            if (ft_strcmp(de->d_name, ".") != 0 && ft_strcmp(de->d_name, "..") != 0)
            {
                if (dirs == NULL)
                    dirs = ls_lstnew(de->d_name);
                else
                    ls_lstadd(dirs, ls_lstnew(de->d_name));
            }
        }
        if (lst == NULL)
        {
            //printf("name = %s\n", de->d_name);
			lst = ls_lstnew(de->d_name);
        }
        else
        {
            //printf("name = %s\n", de->d_name);
            ls_lstadd(lst, ls_lstnew(de->d_name));
        }
    }
	ft_mergesort(&lst);
    while (lst != NULL)
    {
        printf("%s\n", lst->name);
        //printf("%d\n", lst->ptr->d_type);
        lst = lst->next;
    }
	ft_mergesort(&dirs);
	return (dirs);
}