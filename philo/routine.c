#include  "philo.h"

static void	philo_eat(t_philo *philo);
static void	philo_sleep_think(t_philo *philo);

void	*philo_routine(void *arg)
{
	t_philo	*philo;
 
	philo = (t_philo *)arg;
	if (philo->table->nb_of_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, FORK);
		ft_usleep(philo->table->time_to_die, philo->table);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		ft_usleep((philo->table->time_to_eat / 2), philo->table);
	while (!get_end(philo->table))
	{
		philo_eat(philo);
		if (get_end(philo->table))
			break ;
		philo_sleep_think(philo);
	}
	return (NULL);
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, FORK);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	philo->has_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_state(philo, EATING);
	ft_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
 
static void	philo_sleep_think(t_philo *philo)
{
	print_state(philo, SLEEPING);
	ft_usleep(philo->table->time_to_sleep, philo->table);
	print_state(philo, THINKING);
}
