#include "libft.h"

int main(void)
{
	char a[] = "Alex";
	char b[] = "n";
	ft_strcpy(a, ft_strchr(b, 'n') + 1);
	printf("%s\n", a);
}
