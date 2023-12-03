# Philosophers
<p align="center"><img src="https://cdn-images-1.medium.com/v2/resize:fit:1200/1*mb0KkzYAZDDSvdYC2MM5hg.jpeg" width="150" height="150" />

#
<h3><b>¤ Table of contents ¤</b></h3>

1) <b>How to use</b>
2) <b>Introduction</b>
3) <b>Instructions</b>
4) <b>Part 1: Parameters</b>
5) <b>Part 2: Example</b>

---
<h3><b>¤ How to use ¤</b></h3>

* Clone the git repository.
* Execute `make` in terminal.
* Execute the following line in the terminal: `./philo 5 200 50 50 10`
* Change the numbers based on how you wish to test the program.

---
<h3><b>¤ Introduction ¤</b></h3>
<p align="center">In "philosophers", we are first introduced to the concept of processes, threads and mutexes. More specifically, why multithreading is useful feature but also extremely delicate to work with. Up until this point, we have only had to deal with forking, so it adds a new twist to what we have already learned.

---
<h3><b>¤ Instructions ¤</b></h3>

* Project must be written in C.

* Functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors.

* All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and Makefile must not relink.

* Makefile must at least contain the rules $(NAME), all, clean, fclean and re.


---
<h3><b>¤ Part 1: Parameters ¤</b></h3>

<p align="left̨">

* Global variables are forbidden.
* Program should have the following arguments: `number_of_philosophers`, `time_to_die`, `time_to_sleep`, `time_to_eat`, `number_of_times_philo_must_eat` (optional).
* Philosophers must not die.
* Each individual philosopher is a thread.
* There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
* To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them.

---
<h3><b>¤ Part 2: Example ¤</b></h3>
