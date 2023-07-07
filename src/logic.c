#include "../philo.h"

void take_forks(t_philo *philo)
{
	int64_t time;

	pthread_mutex_lock(philo->mutex_right_fork);
	time = get_time() - philo->time_program_start;
	if (philo_died(philo) == true)
	{
		pthread_mutex_unlock(philo->mutex_right_fork);
		return ;
	}
	pthread_mutex_lock(&philo->access->mutex_message);
	printf("%lld %d has taken a right fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->access->mutex_message);
	pthread_mutex_lock(philo->mutex_left_fork);
	time = get_time() - philo->time_program_start;
	if (philo_died(philo) == true)
	{
		pthread_mutex_unlock(philo->mutex_right_fork);
		pthread_mutex_unlock(philo->mutex_left_fork);
		return ;
	}
	pthread_mutex_lock(&philo->access->mutex_message);
	printf("%lld %d has taken a left fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->access->mutex_message);
}

void eating(t_philo *philo)
{
	int64_t time;
	int64_t eat_time_complete;

	time = get_time() - philo->time_program_start;
	if (philo_died(philo) == true)
		return ;
	pthread_mutex_lock(&philo->access->mutex_message);
	printf("%lld %d is eating\n", time, philo->id);
	pthread_mutex_unlock(&philo->access->mutex_message);
	eat_time_complete = get_time() + philo->action_eating;
	while(get_time() <= eat_time_complete)
	{
		if(philo_died(philo) == true)
		{
			pthread_mutex_unlock(philo->mutex_left_fork);
			pthread_mutex_unlock(philo->mutex_right_fork);
			return ;
		}
		usleep(100);
	}
	philo->finished_eating = get_time();
	pthread_mutex_unlock(philo->mutex_left_fork);
	pthread_mutex_unlock(philo->mutex_right_fork);
	philo->eaten_meals++;
}

void sleeping(t_philo *philo)
{
	int64_t time;
	int64_t sleep_time_complete;

	time = get_time() - philo->time_program_start;
	if (philo_died(philo) == true)
		return ;
	pthread_mutex_lock(&philo->access->mutex_message);
	printf("%lld %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->access->mutex_message);
	sleep_time_complete = get_time() + philo->action_sleeping;
	while(get_time() <= sleep_time_complete)
	{
		if(get_time() - philo->finished_eating >= philo->action_death)
			break ;
		usleep(100);
	}
	if (philo_died(philo) == true)
		return ;
}

void thinking(t_philo *philo)
{
	int64_t time;
	
	if (philo_died(philo) == true)
		return ;
	pthread_mutex_lock(&philo->access->mutex_message);
	time = get_time() - philo->time_program_start;
	printf("%lld %d is thinking\n", time, philo->id);
	pthread_mutex_unlock(&philo->access->mutex_message);
}

bool philo_died(t_philo *philo)
{
	int64_t time;

	pthread_mutex_lock(&philo->access->mutex_death);
	if (philo->access->rip_philo == true)
	{
		pthread_mutex_unlock(&philo->access->mutex_death);
		return (true);
	}
	if ((get_time() - philo->finished_eating) >= philo->action_death)
	{
		pthread_mutex_lock(&philo->access->mutex_message);
		time = get_time() - philo->time_program_start;
		printf("%lld %d died\n", time, philo->id);
		pthread_mutex_unlock(&philo->access->mutex_message);
		philo->access->rip_philo = true;
		pthread_mutex_unlock(&philo->access->mutex_death);
		return (true);
	}
	pthread_mutex_unlock(&philo->access->mutex_death);
	return (false);
}
