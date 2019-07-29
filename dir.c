/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:12:45 by keverett          #+#    #+#             */
/*   Updated: 2019/07/15 08:14:53 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <stdio.h> 
#include <dirent.h> 
#include <pwd.h>
#include <sys/errno.h>
#include "ft_ls.h"
#include <stdlib.h>


n_list *ls_lstnew(struct dirent *ptr);

void	ls_lstadd(n_list *head, n_list *new);

n_list *diread(char *path);

// void statprac()
// {
//     struct passwd *p;
//     struct stat sfile;
//     stat("varg.c", &sfile);
//     printf("File's uid is = %o\n", sfile.s);
//     p = getpwuid(sfile.st_uid);
//     printf("PW name is %s\n", p->pw_shell);
    

// }

int main(void) 
{
    // n_list *lst; 
    // n_list *dirs = NULL;

    diread(".");
    // while (lst != NULL)
    // {
    //     printf("%s\n", lst->dir->d_name);
    //     lst = lst->next;
    // }

    // while (dirs != NULL)
    // {
    //     diread((*dirs).dir->d_name);
    //     dirs = dirs->next;
    // }
    //statprac();     
    return (0);
}