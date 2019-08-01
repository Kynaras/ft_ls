#include <stdio.h>
#include <stdlib.h>

int		operation(int a, char o, int b)
{
	int		res;

	res = 0;
	if (o == '+')
		res = a + b;
	if (o == '-')
		res = a - b;
	if (o == '/')
		res = a / b;
	if (o == '*')
		res = a * b;
	if (o == '%')
		res = a % b;
	return (res);
}

int		main(int n, char **v)
{
	int		j;
	int		i;
	int		a[10];

	if (n != 2)
	{
		printf("Error\n");
		return (0);
	}
	a[0] = 0;
	i = -1;
	j = 0;
	while (v[1][j] != '\0')
	{
		if ((v[1][j] >= '0' && v[1][j] <= '9') || ((v[1][j] == '-' && (v[1][j + 1] >= '0' && v[1][j + 1] <= '9'))))
		{
			i++;
			a[i] = atoi(&v[1][j]);
			if (v[1][j] == '-')
				j++;
			while (v[1][j] >= '0' && v[1][j] <= '9' && v[1][j] != '\0')
				j++;
		}
		if (v[1][j] == '-' ||v[1][j] == '+' || v[1][j] == '/' || v[1][j] == '*' || v[1][j] == '%')
		{
			if ((v[1][j] == '/' || v[1][j] == '%') && a[i] == 0)
			{
				printf("Error\n");
				return (0);
			}
			a[i - 1] = operation(a[i - 1], v[1][j], a[i]);
			i = (i - 1);
		}
		j++;
	}
	if (i != 0)
	{
		printf("Error\n");
		return (0);
	}
	printf("%i\n", a[i]);
	return (0);
}
