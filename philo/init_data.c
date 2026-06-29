/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: userzer0 <userzer0@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:01:09 by febranda          #+#    #+#             */
/*   Updated: 2026/06/29 12:56:12 by userzer0         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_data(int ac, char **av)
{
	t_table	*table;

	if (verify_arguments(av))
		return (NULL);
	table = init_table(av);
	if (!table)
		return (NULL);
	table->forks = init_fork_array(av);
	if (!table->forks)
	{
		free(table);
		return (NULL);
	}
	table->philos = init_philo_array(av);
	if (!table->philos)
	{
		ft_clean_forks(table);
		free(table);
		return (NULL);
	}
	return (table);
}

pthread_mutex_t	*init_fork_array(char **av)
{
	pthread_mutex_t	*forks;
	int				num_philos;
	int				i;

	num_philos = ft_atoi(av[1]);
	forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_philo	*init_philo_array(char **av)
{
	t_philo	*philos;
	int		num_philos;
	int		i;

	num_philos = ft_atoi(av[1]);
	philos = malloc(sizeof(t_philo) * num_philos);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal = 0;
		philos[i].has_eaten = 0;
		philos[i].table = table;
		//distribuição dos garfos
		philos[i].left_fork = &table->forks[i];
		philos[i].right_fork = &table->forks[(i + 1) % num_philos];
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		i++;
	}
	return (philos);
}

t_table	*init_table(char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	if (pthread_mutex_init(&table->end_mutex, NULL) != 0)
	{
		free(table);
		return (NULL);
	}
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->end_mutex);
		free(table);
		return (NULL);
	}
	table->nb_of_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->end = 0;
	table->nb_of_meals = -1;
	if (av[5])
		table->nb_of_meals = ft_atol(av[5]);
	table->forks = NULL;
	table->philos = NULL;
	return (table);
}

int	verify_arguments(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (1);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
