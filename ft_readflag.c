/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:08:14 by keverett          #+#    #+#             */
/*   Updated: 2019/07/30 09:08:17 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_readflag(int argc, char **argv, f_list *flags)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		while (argv[i][++j])
		{
			if (argv[i][j] == 't')
				flags->time = 1;
			else if (argv[i][j] == 'l')
				flags->list = 1;
			else if (argv[i][j] == 'r')
				flags->reverse = 1;
			else if (argv[i][j] == 'R')
				flags->recursive = 1;
			else if (argv[i][j] == 'a')
				flags->hidden = 1;
			else
				return(-1);
		}
		j = 0;
	}
return (i);
}