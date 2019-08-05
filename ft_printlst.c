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

void ft_printlst(n_list *lst, f_list flags)
{
	while (lst != NULL)
    {
        if (*lst->name == '.' && flags.hidden == 1)  
            printf("%s\n", lst->name);
        else if (*lst->name != '.')
            printf("%s\n", lst->name);
      lst = lst->next;
    }
	return ;
}