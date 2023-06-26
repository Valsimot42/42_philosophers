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

t_data explained:

	**av ->
	philo_num -> ammount of philosophers
	run_program -> ammount of time for which the program will run (ammount gained from get_time())
	*mutex_forks -> forks that will serve as mutexes, its number equals philosophers number
	mutex_message -> message that will be printed upon executing (e.g. "X is eating", "X is sleeping" etc.)
	mutex_death -> if a philosopher dies, mutex unlocks upon death
	philo_died -> check if philosopher has died, in case the case is true, end program
	
-----

To even run the program, we need to initialize data. To interpret the arguments as numbers, we
will probably need to use atoi.

# Question: should we handle the lone philosopher, or do we print an error if there are less than
#			two philosophers? 

Upon having all the needed elements, we start the program, the rundown of which will be assigned
by get_time() function.

We also need to set the philo_died boolean expression as false.

There can be either 5 or 6 arguments, depending if we want to include number of times each philosopher
must eat. Any other input must print error.

Check if argument is numeric in value (apart from av[0]).

Should program execute if time_to_die is lesser than time_to_eat or time_to_sleep? (probably)

Check for duration of the program here? (yes)

-----

Should next step be initializing mutexes or threads? (mutex)

