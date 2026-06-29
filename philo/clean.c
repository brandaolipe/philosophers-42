/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:42:47 by febranda          #+#    #+#             */
/*   Updated: 2026/06/29 19:42:12 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean_forks(t_table *table)
{
	long	i;

	i = table->nb_of_philo - 1;
	while (i >= 0)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i--;
	}
	free(table->forks);
	table->forks = NULL;
}

void	ft_clean_all(t_table *table)
{
	int	i;

	if (!table)
		return ;
	if (table->philos)
	{
		i = 0;
		while (i < table->nb_of_philo)
		{
			pthread_mutex_destroy(&table->philos[i].meal_mutex);
			i++;
		}
		free(table->philos);
	}
	ft_clean_forks(table);
	pthread_mutex_destroy(&table->end_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	free(table);
}
