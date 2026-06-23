/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:44:41 by febranda          #+#    #+#             */
/*   Updated: 2026/06/23 20:01:41 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	long			last_meal;
	long			has_eaten;
	int				id;
}	t_philo;

typedef struct s_table
{
	t_philo	*philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nb_of_meals;
	long	nb_of_philo;
	int		dead;
}	t_table;

//PARSER
t_table	*init_data(int ac, char **av);
int		verify_arguments(char **av);
long	ft_atol(const char *str);

void	error_message(char *str);

#endif