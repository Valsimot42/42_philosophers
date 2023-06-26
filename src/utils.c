#include "../philo.h"

void err_message(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int is_whitespace(char c)
{
	if (c < 32 || c == 127)
		return (0);
	return (1);
}

int check_valid_arg(char *av)
{
	int i;

	i = 0;
	while(av[i] != '\0')
	{
		if (!ft_isdigit(av[i]) && is_whitespace(av[i]))
			return (1);
		else
			i++;
	}
	return (0);
}

int get_time(void)
{
	struct timeval	time;

	if(gettimeofday(&time, NULL) < 0)
		err_message("ERROR: Issue with time of day");
	return((time.tv_usec / 1000) + (time.tv_usec * 1000));
}

void init_data(t_data *data, int ac, char **av)
{
	int i;

	i = 1;
	if (ac != 5 && ac != 6)
		err_message("ERROR: Incorrect argument input.");
	data->philo_num = ft_atoi(av[1]);
	// if (data->philo_num < 2)
	// 	err_message("Wtf man, he will die!");		// Think about handling 1 philosopher
	while (i < ac)
	{
		if (check_valid_arg(av[i]))
			err_message("ERROR: Please enter numeric value!\n");
		i++;
	}
	if (ft_atoi(av[2]) < (ft_atoi(av[3]) + ft_atoi(av[4])))
		err_message("ERROR:");
	data->run_program = get_time();
	data->rip_philo = false;
}