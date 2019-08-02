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
	n_list *lst = NULL;

    lst = ft_readdir(path);
	
    if (lst)
    {
        ft_mergesort(&lst);
        ft_printlst(lst);
    }
    return;
}
