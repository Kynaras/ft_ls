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

n_list *diread(char *path)
{
    char *str = ft_strdup(path);
    n_list *dirs = NULL;
    struct stat sb;

    DIR *dr = NULL;
    printf("DIRECTORY: %s\n\n", path);
    dr = opendir(path);
    if (dr == NULL)
    {
        printf("Null dir. Path was %s\n", path);
        return (NULL);
    }

    dirs = ft_makelst(dr);
    while (dirs != NULL)
    {
        free(str);
        str = ft_strdup(path);
        ft_join(&str, "/");
        ft_join(&str, (*dirs).ptr->d_name);
        diread(str);
        dirs = dirs->next;
    }
    closedir(dr);
    return (dirs);
}