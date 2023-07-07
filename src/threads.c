#include "../philo.h"

void init_threads(t_philo *philo, t_data *data, char **av, int32_t ac)
{
	int32_t i;

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

void execute_threads(t_philo *philo)
{
	int32_t i;

	i = 0;
	printf("num_philo: %d\n", philo->num_philo);
	while (i < philo->num_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, (void *)philo_run, &philo[i]))
			err_message("ERROR: Thread creation failure!");
		i++;
		usleep(100);
	}
}

void wait_threads(t_philo *philo)
{
	int32_t i;

	i = 0;
	while(i < philo->num_philo)
	{
		if(pthread_join(philo[i].thread, NULL))
			err_message("ERROR: Thread execution failure");
		i++;
	}
}