/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:25:16 by keverett          #+#    #+#             */
/*   Updated: 2019/08/12 10:35:38 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	ft_innersplit(char **time, int i)
{
	char **seconds;
	ft_putchar(' ');
		if (i == 1 && ft_findlen(time[i]) < 2)
				ft_putchar(' ');
		if(i == 3)
		{
			seconds = ft_strsplit(time[i], ':');
			ft_putstr(seconds[0]);
			ft_putchar(':');
			ft_putstr(seconds[1]);
			i = 0;
			while (seconds[i++])
				free(seconds[i]);
	free(seconds);
		}
		else
			ft_putstr(time[i]);
}
void	ft_timesplit(char *str)
{
	int i;

	i = 1;
	char **time;
	char *tmp;

	time = ft_strsplit(str, ' ');
	tmp = time[1];
	time[1] = time[2];
	time[2] = tmp;
	while (time[i] && i <= 3)
	{
		ft_innersplit(time, i);
		i++;
	} 
	i = 0;
	while (time[i++])
		free(time[i]);
	free (time);
	i = 0;
}
