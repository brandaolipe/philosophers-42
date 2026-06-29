/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:36:41 by febranda          #+#    #+#             */
/*   Updated: 2026/06/29 19:38:46 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_died(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->meal_mutex);
	time = get_time() - philo->last_meal;
	if (time >= philo->table->time_to_die)
	{
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

static void	monitor_philos(t_table *table)
{
	int		i;
	int		all_ate_enough;

	while (!get_end(table))
	{
		i = 0;
		all_ate_enough = 0;
		while (i < table->nb_of_philo)
		{
			if (philo_died(&table->philos[i]))
			{
				print_state(&table->philos[i], DIED);
				set_end(table);
				return ;
			}
			pthread_mutex_lock(&table->philos[i].meal_mutex);
			if (table->nb_of_meals != -1
				&& table->philos[i].has_eaten >= table->nb_of_meals)
				all_ate_enough++;
			pthread_mutex_unlock(&table->philos[i].meal_mutex);
			i++;
		}
		if (table->nb_of_meals != -1 && all_ate_enough == table->nb_of_philo)
		{
			set_end(table);
			return ;
		}
		usleep(1000);
	}
}

int	start_simulation(t_table *table)
{
	int	i;

	table->start_time = get_time();
	i = 0;
	while (i < table->nb_of_philo)
	{
		table->philos[i].last_meal = table->start_time;
		if (pthread_create(&table->philos[i].thread, NULL,
				&philo_routine, &table->philos[i]) != 0)
		{
			set_end(table);
			error_message("Error: Failed to create thread\n");
			return (1);
		}
		i++;
	}
	monitor_philos(table);
	i = 0;
	while (i < table->nb_of_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
