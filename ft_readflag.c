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

int 	ft_flagger(char *str, int i, f_list *flags)
{
	int j;

	j = 0;
	while (str[++j])
		{
			if (ft_strcmp(str, "--") == 0)
				return(i);
			else if (str[j] == 't')
				flags->time = 1;
			else if (str[j] == 'l')
				flags->list = 1;
			else if (str[j] == 'r')
				flags->reverse = 1;
			else if (str[j] == 'R')
				flags->recursive = 1;
			else if (str[j] == 'a')
				flags->hidden = 1;
			else if (str[j] == 'A')
				flags->semihidden = 1;
			else if (str[j] == 'G')
				flags->colours = 1;
			else 
				return(-1);
		}
		return (-2);
}
int		ft_readflag(int argc, char **argv, f_list *flags)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		j = ft_flagger(argv[i], i, flags);
		if (j != - 2)
			return (j);
	}
	return (i);
}