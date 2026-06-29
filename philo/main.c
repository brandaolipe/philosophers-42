/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:11:31 by febranda          #+#    #+#             */
/*   Updated: 2026/06/29 19:43:14 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
	{
		error_message("Error: Wrong number of arguments\n");
		return (1);
	}
	if (verify_arguments(av))
		return (1);
	table = init_data(av);
	if (!table)
	{
		error_message("Error: Invalid arguments\n");
		return (1);
	}
	start_simulation(table);
	ft_clean_all(table);
	return (0);
}
