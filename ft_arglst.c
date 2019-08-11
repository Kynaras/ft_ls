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

n_list *ft_arglst(int argc, char **argv, int i)
{
	int index;
	n_list *args;

	args = NULL;
	index = i;

	while (index < argc)
	{
		if (args == NULL)
			args = ls_lstnew(argv[index], ".");
		else
			ls_lstadd(args, ls_lstnew(argv[index], "."));
		index++;
	}
	return (args);
}
