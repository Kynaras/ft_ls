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

#include "ft_ls.h"

int main(int argc, char **argv) 
{
    f_list flags;
    int ers;

    ft_flagset(&flags);
    ft_readflag(argc, argv, &flags);
    ers = ft_flagcount(&flags);
    if (argc == 2)
    {
        ft_readdir(".", flags);
        return (0);  
    }
    // if (flags.recursive = 1 && flags.hidden->) 
    //     ft_readflag(argc, argv, &flags);
  
    // else
    // {
    //     ers = ft_checkflags(argc, argv);
    //     if (ers == -1)
    //     {
    //         ft_putstr("ls: illegal option\n");
    //         ft_putstr("usage: ft_ls [-Ralrt] [file ...]\n");
    //         return (0);
    //    }
        // if (ers == 0)
        // {
        //     ft_readfiles();
        // }

   
   // diread(".");
   return (0);
}
//}