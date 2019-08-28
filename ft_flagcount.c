/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 08:39:59 by keverett          #+#    #+#             */
/*   Updated: 2019/08/05 08:40:00 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_flagcount(f_list *flags)
{
	int i;

	i = 0;
	if (flags->hidden == 1 || flags->list == 1 || flags->recursive == 1 ||
		flags->reverse == 1 || flags->time == 1)
		i++;
	return (i);
}
