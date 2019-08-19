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

n_list *ft_arglst(int argc, char **argv, int i, int type)
{
	int index;
	n_list *args;
	DIR *dr;
	index = i;
	args = NULL;

	  if (ft_strcmp(argv[index], "--") == 0)
	 	index++;
	while (index < argc)
	{
		if(!(dr=opendir(argv[index])) && type == 1)
		{
			if (args == NULL)
				args = ls_lstnew(argv[index], ".");
			else
				ls_lstadd(args, ls_lstnew(argv[index], "."));
		}
		else if ((dr = opendir(argv[index])) && type == 2)
		{
			if (args == NULL)
				args = ls_lstnew(argv[index], ".");
			else
				ls_lstadd(args, ls_lstnew(argv[index], "."));
			closedir(dr);
		}
		index++;
	}

	return (args);
}
