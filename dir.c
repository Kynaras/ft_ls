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
    int ers;

    ers = 0;
    if (argc == 1)
    {
        ft_lss(".");
        return (0);  
    }
    else
        ers = ft_readflags(argv[1]);
    if (ers == 0)
        ft_onlynames(int argc, char **argv)
ls
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