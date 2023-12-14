/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:46:20 by ljh               #+#    #+#             */
/*   Updated: 2023/12/14 01:21:45 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    number_of_philosophers time_to_die time_to_eat time_to_sleep
    [number_of_times_each_philosopher_must_eat]

    memset, printf, malloc, free, write, usleep, gettimeofday, 

    pthread_create, pthread_detach, pthread_join, 

    pthread_mutex_init, pthread_mutex_destroy, 
    pthread_mutex_lock, pthread_mutex_unlock
*/

#ifndef PHILO_H
# define PHILO_H

# define EBUSY 16

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_condition
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_must_eat;
}	t_condition;

typedef struct s_philo
{
	int	philo_idx;
}	t_philo;

typedef struct s_pinfo
{
	pthread_mutex_t	*fork;
	t_philo			*philo;
	pthread_t		*pthread;
	int				*fork_stat;
	t_condition		info;
}	t_pinfo;

#endif