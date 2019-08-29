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

void	ft_innersplit(char **timer, int i, struct stat *sb)
{
	char **seconds;

	if (i == 1 && ft_findlen(timer[i]) < 2)
		ft_putchar(' ');
	if (i == 3 && ((time(NULL) - sb->st_mtime) >= 15770000 || time(NULL) <
	sb->st_mtime))
	{
		ft_putchar(' ');
		write(1, timer[4], 4);
	}
	else if (i == 3)
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
	else
		ft_putstr(timer[i]);
}

void	ft_timesplit(char *str, struct stat *sb)
{
	int		i;
	char	**time;
	char	*tmp;

	i = 1;
	time = ft_strsplit(str, ' ');
	tmp = time[1];
	time[1] = time[2];
	time[2] = tmp;
	while (time[i] && i <= 3)
	{
		ft_putchar(' ');
		ft_innersplit(time, i, sb);
		i++;
	}
	i = 0;
	while (time[i])
	{
		free(time[i]);
		i++;
	}
	free(time);
	i = 0;
}
