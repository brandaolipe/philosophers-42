/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: userzer0 <userzer0@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:11:31 by febranda          #+#    #+#             */
/*   Updated: 2026/06/29 12:56:19 by userzer0         ###   ########.fr       */
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
	table = init_data(ac, av);
	if (!table)
	{
		error_message("Error: Invalid arguments\n");
		return (1);
	}
	start_simulation(table);
	return (0);
}
