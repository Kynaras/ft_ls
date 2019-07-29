/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:37:46 by keverett          #+#    #+#             */
/*   Updated: 2019/06/04 15:00:15 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int num;
	long long int i;
	long long int sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\t')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	num = num * sign;
	return (num);
}
