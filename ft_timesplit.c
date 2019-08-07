/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:25:16 by keverett          #+#    #+#             */
/*   Updated: 2019/08/07 15:25:17 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_timesplit(char *str)
{
	int i;

	i = 1;
	char **time;
	char **seconds;

	time = ft_strsplit(str, ' ');
	while (time[i])
	{
		ft_putchar(' ');
		if(i == 3)
		{
			seconds = ft_strsplit(time[i], ':');
			ft_putstr(seconds[0]);
			ft_putchar(':');
			ft_putstr(seconds[1]);
		}
		else
			ft_putstr(time[i]);
		i++;
	} 
	i = 0;
	while (time[i])
	{
		free(time[i]);
		i++;
	}
	free (time);
	i = 0;
	while (seconds[i])
	{
		free(seconds[i]);
		i++;
	}
	free(seconds);
}
