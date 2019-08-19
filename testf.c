/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:12:45 by keverett          #+#    #+#             */
/*   Updated: 2019/08/12 10:36:26 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv) 
{
    vs_list vars;
    vars.lst = NULL;
    vars.i = 0;

    ft_flagset(&vars.flags);
    

    if (argc > 1)
        vars.i = ft_readflag(argc, argv, &vars.flags);

    if (vars.i == -1)
    {
        vars.error = ft_finderror(argc, argv);
        ft_putstr("ft_ls: illegal option -- ");
        ft_putchar (vars.error);
        ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]");
        // sleep(30);
        return (0);
    }
    if (argc == 1 || argc == vars.i || (argc - vars.i == 1 && ft_strcmp(argv[vars.i], "--") == 0))
    {
        vars.dirs = ft_readdir(".", vars.flags);
        ft_dellst(vars.dirs);
		// sleep (30);
        return (0);  
    }

    else if (argc >= 2)
    {
        vars.j = 0;
        while (++vars.j <= 2)
        {
            vars.lst = vars.j == 1 ? ft_arglst(argc, argv, vars.i, 1) : ft_arglst(argc, argv, vars.i, 2);
            ft_mergesort(&vars.lst, vars.flags);
            ft_structstat(vars.lst);
            vars.dirs = vars.lst;
            if (vars.lst != NULL)
            {
                while (vars.lst)
                {
                    if (vars.j >= 2 && S_ISDIR(vars.lst->sb.st_mode))
                    {
                        ft_putstr(vars.lst->name);
                        ft_putstr(":\n");
                    }
                    ft_readdir(vars.lst->name, vars.flags);
                    vars.lst = vars.lst->next;
                    if (vars.j >=2)
                        vars.j++;
                }
            }
            // else
            //     vars.dirs = ft_readdir(".", vars.flags);
            ft_dellst(vars.dirs);
        }
    }
//   sleep(30); 
   return (0);
}
//}
