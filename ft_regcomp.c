#include "ft_ls.h"

void	ft_regcomp(n_list *a, n_list *b, n_list **result, f_list flags)
{
if (ft_strcmp((*a).name, (*b).name) <= 0)
	{
		(*result) = flags.reverse ? b : a;
		(*result)->next = flags.reverse ? sortlist(b->next, a, flags) : sortlist (a->next, b, flags);
	}
	else
	{
		*result = flags.reverse ? a : b;
		(*result)->next = flags.reverse ? sortlist(b, a->next, flags) : sortlist(a, b->next, flags);
	}
}