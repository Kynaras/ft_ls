/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlynames.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:04:23 by keverett          #+#    #+#             */
/*   Updated: 2019/07/31 12:04:27 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
void	ft_only_names(int argc, char **argv)
{
	int i;
	n_list *lst;
	n_list *dirs;
	DIR *dr;

	i = 1;
	lst = NULL;
	neg = NULL;
	
	while (i < argc)
	{
		ft_errorcheck(argv[i], &lst, &dirs)
		i++
	}
	}
}