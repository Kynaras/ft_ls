/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:00:03 by keverett          #+#    #+#             */
/*   Updated: 2019/08/02 12:57:49 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flagset(t_f_list *flags)
{
	flags->recursive = 0;
	flags->reverse = 0;
	flags->time = 0;
	flags->hidden = 0;
	flags->list = 0;
	flags->semihidden = 0;
	flags->colours = 0;
	flags->groups = 0;
	flags->unsorted = 0;
	flags->users = 0;
	return ;
}
