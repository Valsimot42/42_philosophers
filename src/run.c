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