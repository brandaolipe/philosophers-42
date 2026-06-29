/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:40:15 by febranda          #+#    #+#             */
/*   Updated: 2026/06/29 19:40:51 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	get_end(t_table *table)
{
	int	status;

	pthread_mutex_lock(&table->end_mutex);
	status = table->end;
	pthread_mutex_unlock(&table->end_mutex);
	return (status);
}

void	set_end(t_table *table)
{
	pthread_mutex_lock(&table->end_mutex);
	table->end = 1;
	pthread_mutex_unlock(&table->end_mutex);
}

void	ft_usleep(long time_in_ms, t_table *table)
{
	long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
	{
		if (get_end(table))
			break ;
		usleep(500);
	}
}

void	print_state(t_philo *philo, char *status)
{
	long	time;

	pthread_mutex_lock(&philo->table->print_mutex);
	time = get_time() - philo->table->start_time;
	if (!get_end(philo->table))
	{
		printf("%ld %d %s\n", time, philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}
