/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:05:41 by keverett          #+#    #+#             */
/*   Updated: 2019/07/23 16:05:43 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

n_list *ft_diread(char *path)
{
    char *str;
    n_list *dirs;
    struct stat sb;

    
    DIR *dr = NULL;
    dr = opendir(path);
    if (dr == NULL)
        return (NULL);

    dirs = ft_makelst(dr);
    while (dirs != NULL)
    {
        str = ft_strdup(path);
        ft_join(&str, "/");
        ft_join(&str, (*dirs).name);
        ft_diread(str);
        dirs = dirs->next;
        free(str);
    }
    closedir(dr);
    return (dirs);
}