#include "../philo.h"

int main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;

	philo = NULL;
	init_data(&data, ac, av);
	create_mutex(&data);
	philo = malloc(sizeof(t_philo) * data.philo_num);
	if (!philo)
		err_message("ERROR: Philosopher mallocing failed");
	init_threads(philo, &data, ac, av);
	execute_threads(philo);
	wait_threads(philo);
	destroy_mutex(&data);
	free(philo);
	free(data.mutex_forks);
	return (0);
}