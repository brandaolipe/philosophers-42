/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:44:41 by febranda          #+#    #+#             */
/*   Updated: 2026/06/29 19:35:35 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define FORK		"has taken a fork"
# define DIED		"died"

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	pthread_t		thread;
	t_table			*table;
	long			last_meal;
	long			has_eaten;
	int				id;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_of_meals;
	long			nb_of_philo;
	int				end;
}	t_table;

// PARSER
t_table			*init_data(char **av);
pthread_mutex_t	*init_fork_array(char **av);
t_philo			*init_philo_array(t_table *table, char **av);
t_table			*init_table(char **av);
int				verify_arguments(char **av);

// UTILS
void			error_message(char *str);
long			ft_atol(const char *str);
int				ft_atoi(const char *str);
long			get_time(void);
int				get_end(t_table *table);
void			set_end(t_table *table);
void			ft_usleep(long time_in_ms, t_table *table);
void			print_state(t_philo *philo, char *status);

void			*philo_routine(void *arg);
int				start_simulation(t_table *table);

void			ft_clean_forks(t_table *table);
void			ft_clean_all(t_table *table);

#endif