/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:01:57 by tbolkova          #+#    #+#             */
/*   Updated: 2023/06/24 16:08:05 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct 			s_data {
	char			**av;
	int				philo_num;
	int				run_program;
	char			*err_msg;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_message;
	pthread_mutex_t	mutex_death;
	bool			rip_philo;
}						t_data;

typedef struct 	s_philo {
	int		id;
	
	
} 				t_philo;

//!-------------SRC---------------

// main.c
int main(int ac, char **av);


// utils.c
void init_data(t_data *data, int ac, char **av);
void err_message(char *msg);


// libft_utils.c
size_t	ft_strlen(const char *s);
int	ft_atoi(const char *str);

#endif








// typedef struct s_data
// {
// 	char			**av;
// 	int32_t			amount_philos;
// 	int64_t			start_program;
// 	pthread_mutex_t	*mutex_forks;
// 	pthread_mutex_t	mutex_message;
// 	pthread_mutex_t	mutex_death;
// 	bool			philo_died;
// }				t_data;

// typedef struct s_philo
// {	
// 	int32_t			eaten_meals;
// 	int32_t			amount_philos;
// 	int32_t			id;
// 	int64_t			time_routine_start;
// 	int64_t			time_program_starts;
// 	int64_t			finished_eating;
// 	int64_t			tt_die;
// 	int64_t			tt_eat;
// 	int64_t			tt_sleep;
// 	int64_t			times_philo_eats;
// 	pthread_t		thread;
// 	pthread_mutex_t	*mutex_left_fork;
// 	pthread_mutex_t	*mutex_right_fork;
// 	t_data			*access;
// }				t_philo;
