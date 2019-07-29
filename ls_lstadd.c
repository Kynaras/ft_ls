/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:14:33 by keverett          #+#    #+#             */
/*   Updated: 2019/07/22 13:15:53 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void	ls_lstadd(n_list *head, n_list *new)
{
    n_list *tmp;
    tmp = head;

    if (head == NULL || new == NULL)
    {
        return;
    }
    
    while (tmp)
    {
        if (tmp->next == NULL)
        {
            break;
        }
        tmp = tmp->next;
    }
    tmp->next = new;   
}