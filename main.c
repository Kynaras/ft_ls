/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 08:12:45 by keverett          #+#    #+#             */
/*   Updated: 2019/08/12 10:36:26 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_multiargs(t_vs_list *vars, int *argc, char ***argv)
{
	t_n_list *tmp;

	vars->j = 0;
	while (++vars->j <= 3)
	{
		vars->lst = ft_arglst(*argc, *argv, vars->i, vars->j);
		ft_structstats(vars->lst);
		if (vars->flags.unsorted == 0)
			ft_mergesort(&vars->lst, &vars->flags);
		vars->dirs = vars->lst;
		while (vars->lst)
		{
			if (S_ISDIR(vars->lst->sb.st_mode))
				ft_putthis(vars->lst->name);
			tmp = ft_readdir(vars->lst->name, &vars->flags);
			ft_dellst(tmp);
			vars->lst = vars->lst->next;
		}
		ft_dellst(vars->dirs);
	}
}

int		main(int argc, char **argv)
{
	t_vs_list vars;

	vars.lst = NULL;
	vars.dirs = NULL;
	vars.i = 0;
	ft_flagset(&vars.flags);
	if (argc > -1 && (vars.i = ft_readflag(argc, argv, &vars.flags)) == -1)
	{
		vars.error = ft_finderror(argc, argv);
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(vars.error);
		ft_putstr("\nusage: ft_ls [-AGRafglort] [file ...]");
		return (0);
	}
	if (argc == 1 || argc == vars.i || (argc - vars.i == 1 &&
	ft_strcmp(argv[vars.i], "--") == 0))
	{
		vars.dirs = ft_readdir(".", &vars.flags);
		ft_dellst(vars.dirs);
		return (0);
	}
	else if (argc >= 2)
		ft_multiargs(&vars, &argc, &argv);
	return (0);
}
