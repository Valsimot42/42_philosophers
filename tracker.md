Example of an input for philosophers:

	./philo 5 10000 2000 2000 50(*)
		|	|	|	  |	   |   |
		V   |   |     |    |   |
	av[0]	V   |     |    |   |
		av[1]   V     |    |   |
		    av[2]     V    |   |
				  av[3]    V   |
				  	   av[4]   V
					   	   av[5](optional argument)

	av[0]: program name
	av[1]: number_of_philosophers
	av[2]: time_to_die
	av[3]: time_to_eat
	av[4]: time_to_sleep
	av[5]: number_of_times_each_philo_must_eat (optional argument)


Two structs will be used, t_data and t_philo:

•	t_data will hold information for global usage of program (e.g. start program, amount of philo,
	mutex death, etc.)

•	t_philo will hold information about philosophers (e.g. time to eat, time to sleep, amount of
	eaten meals, etc.)

