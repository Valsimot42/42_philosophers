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
	philo_num -> amount of philosophers
	run_program -> amount of time for which the program will run (ammount gained from get_time())
	*mutex_forks -> forks that will serve as mutexes, its number equals philosophers number
	mutex_message -> message that will be printed upon executing (e.g. "X is eating", "X is sleeping" etc.)
	mutex_death -> if a philosopher dies, mutex unlocks upon death
	philo_died -> check if philosopher has died, in case the case is true, end program
	
t_philo explained:

	id -> identification for amount of threads (philosophers)
	eaten_meals -> amount of times philosopher ate a meal
	num_philo -> amount of philosophers
	time_routine_start -> 
	time_program_start ->
	times_philo_eats -> amount of time routine will repeat
	action_death -> checks if philosopher is dead
	action_eating -> checks if philosopher is eating
	action_sleeping -> checks if philosopher is sleeping
	finished_eating -> checks if philosopher has finished eating
	thread ->
	mutex_left_fork ->
	mutex_right_fork ->
	access ->

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

# Question: if forks are mutexes, how will it behave in our code?

Obviously, the number of forks must be the same as the number of philosophers at the table.

NOTE: to properly allocate memory for the mutexes, we must allocate sizeof(pthread_mutex_t) type.

-----

Going back to our main, we must make sure to allocate memory for all the threads (philos) that will
be executed during our program.

Of course, if there is an error with memory allocation, we need to protect it.

After we have allocated memory, we can initialize said threads (philosophers).

-----

