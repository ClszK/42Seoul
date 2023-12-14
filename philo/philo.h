/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:46:20 by ljh               #+#    #+#             */
/*   Updated: 2023/12/15 05:58:48 by ljh              ###   ########.fr       */
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

typedef enum	t_pstat {
    EAT,
	THINK,
	SLEEP
}	e_pstat;

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
	int				*left_fork;
	pthread_mutex_t	*left_m;
	int				*right_fork;
	pthread_mutex_t	*right_m;
	t_condition		*info;
	e_pstat			pstate;
	pthread_mutex_t	*pstate_m;
	int				philo_idx;
	int				eat_cnt;
	int				start_eat;
}	t_philo;

typedef struct s_pinfo
{
	pthread_mutex_t	*fork;
	int				*fork_stat;
	pthread_mutex_t	*pstat_m;
	t_philo			*philo;
	pthread_t		*pthread;
	t_condition		info;
}	t_pinfo;

#endif