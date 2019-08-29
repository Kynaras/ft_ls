/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:11:45 by keverett          #+#    #+#             */
/*   Updated: 2019/08/28 17:11:46 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_size(struct stat *sb, t_s_list *totals)
{
	int numsize;
	int i;

	numsize = ft_numcount(sb->st_size);
	i = totals->size - numsize;
	while (i)
	{
		ft_putchar(' ');
		i--;
	}
}
