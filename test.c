#include "ft_ls.h"

int main()
{
	DIR *dr;

	{
		if(!(dr = opendir("perm")))
		{
			perror("Error ");
		}
	}
}
