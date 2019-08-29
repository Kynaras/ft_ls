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

void	ls_lstadd(t_n_list *head, t_n_list *new)
{
    if (head == NULL || new == NULL)
        return;
    head->last->next = new;
    head->last = new;  
}