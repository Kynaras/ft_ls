#include "ft_ls.h"

int main()
{
	f_list flags = { 1, 0, 0, 0, 1};

	printf("%i, %i", flags.recursive, flags.reverse);
	return(0);
}
