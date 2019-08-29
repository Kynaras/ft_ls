/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:26:11 by keverett          #+#    #+#             */
/*   Updated: 2019/08/29 16:26:13 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_n_list	*sortlist(t_n_list *a, t_n_list *b, t_f_list *flags)
{
	t_n_list *result;

	result = NULL;
	if (a == NULL)
	{
		return (b);
	}
	if (b == NULL)
	{
		return (a);
	}
	if (flags->time == 1)
		ft_timecmp(a, b, &result, flags);
	else
		ft_regcomp(a, b, &result, flags);
	return (result);
}
