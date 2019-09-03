/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arglst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:37:00 by keverett          #+#    #+#             */
/*   Updated: 2019/08/06 15:37:01 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_checker(t_n_list **args, char *argv, int type)
{
	if (type == 1 && errno == 2)
	{
		if (*args == NULL)
			*args = ls_lstnew(argv, ".");
		else
			ls_lstadd(*args, ls_lstnew(argv, "."));
	}
	else if (type == 2 && errno != 13 && errno != 2)
	{
		if (*args == NULL)
			*args = ls_lstnew(argv, ".");
		else
			ls_lstadd(*args, ls_lstnew(argv, "."));
	}
	else if (type == 3 && errno == 13)
	{
		if (*args == NULL)
			*args = ls_lstnew(argv, ".");
		else
			ls_lstadd(*args, ls_lstnew(argv, "."));
	}
}

void		ft_lstmaker(t_n_list **args, char *argv, int type)
{
	DIR *dr;

	dr = NULL;
	if (!(dr = opendir(argv)))
		ft_checker(args, argv, type);
	else if (type == 4)
	{
		if (*args == NULL)
			*args = ls_lstnew(argv, "");
		else
			ls_lstadd(*args, ls_lstnew(argv, ""));
		closedir(dr);
	}
	else
		closedir(dr);
}

t_n_list	*ft_arglst(int argc, char **argv, int i, int type)
{
	int			index;
	t_n_list	*args;

	index = i;
	args = NULL;
	if (ft_strcmp(argv[index], "--") == 0)
		index++;
	while (index < argc)
	{
		ft_lstmaker(&args, argv[index], type);
		index++;
	}
	return (args);
}
