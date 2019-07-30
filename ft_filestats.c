/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filestats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:59:11 by keverett          #+#    #+#             */
/*   Updated: 2019/07/29 15:59:12 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_filestats(char *path)
{
	int i = 0;
	struct stat sb = NULL;
	if (lstat(path, &sb) != -1)
	
	while (i <= 10)
	{
		if (S_ISDIR(sb.st_mode) && i == 0)
			ft_putchar('d');
		else if (S_ISLNK(sb.st_mode) && i == 0)
			ft_putchar('l');
		else if (S_IRUSR(sb.st_mode) && i == 1)
			ft_putchar('r');
		else if (S_IWUSR(sb.st_mode) && i == 2)
			ft_putchar('w');
		else if (S_IXUSR(sb.st_mode) && i == 3)
			ft_putchar('x');
		else if (S_IRGRP(sb.st_mode) && i == 4)
			ft_putchar('r');
		else if (S_IWGRP(sb.st_mode) && i == 5)
			ft_putchar('w');
		else if (S_IXGRP(sb.st_mode) && i == 6)
			ft_putchar('x');
		else if (S_IROTH(sb.st_mode) && i == 7)
			ft_putchar('r');
		else if (S_IWOTH(sb.st_mode) && i == 8)
			ft_putchar('w');
		else if (S_IXOTH(sb.st_mode) && i == 9)
			ft_putchar('x');
		else
			ft_putchar('-');
	}
}