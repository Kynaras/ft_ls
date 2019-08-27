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

void 	ft_innersplit(char **timer, int i, struct stat *sb)
{
	char **seconds;
	ft_putchar(' ');
		if (i == 1 && ft_findlen(timer[i]) < 2)
				ft_putchar(' ');
		if(i == 3)
		{
			if ((time(NULL) - sb->st_mtime) >= 16070400 || time(NULL) < sb->st_mtime)
			{
				ft_putchar(' ');
				write(1, timer[4], 4);
			}
			else
			{
			seconds = ft_strsplit(timer[i], ':');
			ft_putstr(seconds[0]);
			ft_putchar(':');
			ft_putstr(seconds[1]);
			i = 0;
			while (seconds[i])
				free(seconds[i++]);
			free(seconds);
			}
		}
		else
			ft_putstr(timer[i]);
}
void	ft_timesplit(char *str, struct stat *sb)
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
		ft_innersplit(time, i, sb);
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
}
