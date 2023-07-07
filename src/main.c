#include "../philo.h"

void philo_run(t_philo *philo)
{
	philo->time_routine_start = get_time();
	philo->finished_eating = philo->time_routine_start;
	if (philo->id % 2 == 0)
	{
		if (philo->num_philo < 100)
			usleep(100);
		else
			usleep(1500);
	}
	while (1)
	{
		take_forks(philo);
		eating(philo);
		if (philo->access->rip_philo == true)
			break ;
		if (philo->eaten_meals == philo->times_philo_eats)
			exit(0);
		sleeping(philo);
		thinking(philo);
	}
}

int main(int32_t ac, char **av)
{
	t_data		data;
	t_philo		*philo;

	philo = NULL;
	init_data(&data, ac, av);
	create_mutex(&data);
	philo = malloc(sizeof(t_philo) * data.philo_num);
	if (!philo)
		err_message("ERROR: Philosopher mallocing failed");
	init_threads(philo, &data, av, ac);
	execute_threads(philo);
	wait_threads(philo);
	destroy_mutex(&data);
	free(philo);
	free(data.mutex_forks);
	return (0);
}