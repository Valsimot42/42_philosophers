#include "../philo.h"

// void *start_execution(void *arg)
// {

// }

int main(int ac, char **av)
{
	t_data		data;
	pthread_t	philo;

	philo = NULL;
	init_data(&data, ac, av);
	create_mutex(&data);
	philo = malloc(sizeof(t_philo) * data.philo_num);
	if (!philo)
		err_message("ERROR: Philosopher mallocing failed");
	init_threads(philo, &data, ac, av);
	// pthread_create();
	// pthread_join();
	destroy_mutex(&data);
	return (0);
}