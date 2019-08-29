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

int	ft_flaglet(char *str, int *j, t_f_list *flags)
{
	if (str[*j] == 'A')
		flags->semihidden = 1;
	else if (str[*j] == 'G')
		flags->colours = 1;
	else if (str[*j] == 'g')
	{
		flags->list = 1;
		flags->groups = 1;
	}
	else if (str[*j] == 'f')
		flags->unsorted = 1;
	else if (str[*j] == 'o')
	{
		flags->users = 1;
		flags->list = 1;
	}
	else
		return (-1);
	return (-2);
}

int	ft_flagger(char *str, int i, t_f_list *flags)
{
	int j;

	j = 0;
	while (str[++j])
	{
		if (ft_strcmp(str, "--") == 0)
			return (i);
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
		else if (ft_flaglet(str, &j, flags) == -1)
			return (-1);
	}
	return (-2);
}

int	ft_readflag(int argc, char **argv, t_f_list *flags)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		j = ft_flagger(argv[i], i, flags);
		if (j != -2)
			return (j);
	}
	return (i);
}
