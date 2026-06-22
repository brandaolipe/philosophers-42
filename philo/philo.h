/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:44:41 by febranda          #+#    #+#             */
/*   Updated: 2026/06/22 20:08:07 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>

typedef struct s_table
{
	t_philo	*philos; // vetor de filosofos
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nb_of_meals;
	int		nb_of_philo;
	int		dead;
}	t_table;

#endif