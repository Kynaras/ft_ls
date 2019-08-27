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

void ft_lstmaker(n_list **args, char *argv, int type)
{
	DIR *dr;

	dr = NULL;
	if(!(dr = opendir(argv)))
		{
			if (type == 1)
			{
			 if (*args == NULL)
			 	 *args = ls_lstnew(argv, ".");
			 else
				 ls_lstadd(*args, ls_lstnew(argv, "."));
			}
		}
	else if (type == 2)
		{
			if (*args == NULL)
				*args = ls_lstnew(argv, ".");
			else
				ls_lstadd(*args, ls_lstnew(argv, "."));
		}
	 else
    	closedir(dr);
}

n_list *ft_arglst(int argc, char **argv, int i, int type)
{
	int index;
	n_list *args;
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
