#include "../philo.h"

void init_threads(t_philo *philo, t_data *data, int ac, char **av)
{
	int i;

	i = 0;
	while (i < data->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].action_death = ft_atoi(av[2]);
		philo[i].action_eating = ft_atoi(av[3]);
		philo[i].action_sleeping = ft_atoi(av[4]);
		if (ac == 6)
			philo[i].times_philo_eats = ft_atoi(av[5]);
		philo[i].eaten_meals = 0;
		philo[i].finished_eating = data->run_program;
		philo[i].mutex_right_fork = &data->mutex_forks[i];
		philo[i].mutex_left_fork = \
							&data->mutex_forks[(i + 1) % data->philo_num];
		philo[i].access = data;
		philo[i].time_program_start = data->run_program;
		philo[i].num_philo = data->philo_num;
		i++;
	}
}