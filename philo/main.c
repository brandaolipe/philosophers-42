/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:11:31 by febranda          #+#    #+#             */
/*   Updated: 2026/06/22 20:02:07 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
	{
		error_message("Error: Wrong number of arguments\n");
		return (1);
	}
	table = init_table(ac, av);
	if (!table)
	{
		error_message("Error: Invalid arguments\n");
		return (1);
	}
	//init_routines
	//free table
	return (0);
}
