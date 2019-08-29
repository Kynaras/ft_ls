/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalsizelst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:05:09 by keverett          #+#    #+#             */
/*   Updated: 2019/08/20 11:05:10 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_s_list ft_totalsizelst(t_n_list *lst)
{
	t_s_list totals;

	totals.unamesize = ft_findtotsize(lst, 1);
	totals.gnamesize = ft_findtotsize(lst, 2);
	totals.linksize = ft_findsize(lst, 1);
	totals.size = ft_findsize(lst, 2);
	return (totals);
}

