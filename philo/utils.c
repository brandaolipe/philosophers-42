/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:25:06 by febranda          #+#    #+#             */
/*   Updated: 2026/06/23 20:01:59 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Maior long: 9223372036854775807
//Menor long:-9223372036854775808

long	ft_atol(const char *str)
{
	long	number;
	long	sign;

	number = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	return (number * sign);
}

void	error_message(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, str[i], 1);
		i++;
	}
}