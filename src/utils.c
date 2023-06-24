#include "../philo.h"

void err_message(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void init_data(t_data *data, int ac, char **av)
{
	//int i;
	(void)data;
	(void)av;
	if (ac != 5 && ac != 6)
		err_message("Incorrect argument input:");
	
	
}