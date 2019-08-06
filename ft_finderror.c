/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finderror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:44:10 by keverett          #+#    #+#             */
/*   Updated: 2019/08/06 11:46:29 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_finderror(int argc, char **argv)
{
	int i;
	int j;
	
	i = 0;
	j = 1;
	while (++i < argc && argv[i][0] == '-')
	{
		while (argv[i][j])
		{
			if (argv[i][j] != 't' && argv[i][j] != 'l' && argv[i][j] != 'r' 
			&& argv[i][j] != 'R' && argv[i][j] != 'a')
			{
			 	return (argv[i][j]);
			}
			j++;
		}
		j = 0;
	}
	return (argv[i][j]);
}
