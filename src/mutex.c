#include "../philo.h"

void create_mutex(t_data *data)
{
	int32_t i;

	i = 0;
	data->mutex_forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->mutex_forks)
		err_message("ERROR: Fork malloc failed.");
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->mutex_forks[i], NULL))
			err_message("ERROR: Fork mutex creation failed.");
		i++;
	}
	if (pthread_mutex_init(&data->mutex_message, NULL))
		err_message("ERROR: Message mutex creation failed.");
	if (pthread_mutex_init(&data->mutex_death, NULL))
		err_message("ERROR: Death mutex creation failed.");
}

void destroy_mutex(t_data *data)
{
	int32_t i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_mutex_destroy(&data->mutex_forks[i]))
			err_message("ERROR: Fork mutex destruction failed.");
		i++;
	}
	if (pthread_mutex_destroy(&data->mutex_message))
		err_message("ERROR: Message mutex destruction failed.");
	if (pthread_mutex_destroy(&data->mutex_death))
		err_message("ERROR: Death mutex destruction failed.");
}