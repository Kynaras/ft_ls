#include "ft_ls.h"

n_list *sortlist(n_list *a, n_list *b, f_list *flags)
{
	n_list *result;
	result = NULL;

	if (a == NULL)
	{
		return (b);
	}
	if (b == NULL)
	{
		return (a);
	}

	if (flags->time == 1)
		ft_timecmp(a, b, &result, flags);
	else
		ft_regcomp(a, b, &result, flags);
	 
	return (result);
}