/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:46:20 by ljh               #+#    #+#             */
/*   Updated: 2023/12/24 06:31:03 by ljh              ###   ########.fr       */
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

# define EAT 0
# define THINK 1
# define SLEEP 2
# define FORK 3

# define ALIVE 0
# define DIE 1

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
	int				*left_fork;
	int				*right_fork;
	pthread_mutex_t	*left_m;
	pthread_mutex_t	*right_m;
	t_condition		*info;
	pthread_mutex_t alive_m;
	int				alive;
	int				philo_idx;
	int				eat_cnt;
	long			start;
	long			start_eat;
	pthread_mutex_t start_eat_m;
	pthread_mutex_t	*print_m;
}	t_philo;

typedef struct s_pinfo
{
	pthread_mutex_t	*fork;
	int				*fork_stat;
	t_philo			*philo;
	pthread_t		*pthread;
	t_condition		info;
	pthread_mutex_t	print_m;
}	t_pinfo;

/* info_set.c */
void	init_pinfo(t_pinfo *pinfo);
int		condition_set(t_condition *info, int argc, char *argv[], int option);
int		create_pinfo(t_pinfo *pinfo);
int		set_philo(t_pinfo *pinfo, t_philo *philo);
int		create_philo(t_pinfo *pinfo);

/* utils.c */
int		ft_atoi(const char *str);
int		ft_usleep(t_philo *philo, long start, int time);
long	get_ms(void);
void	philo_fork_down(t_philo *philo);

/* philo.c */
void	*start_philo_even(void *param);
void	*start_philo_odd(void *param);

int		philo_die(t_philo *philo);

void	philo_stat_print(t_philo *philo, char *str);
void	clean_pinfo(t_pinfo *pinfo);
int		philo_die(t_philo *philo);
int		philo_think_even(t_philo *philo);
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
void	*start_philo_odd(void *param);
void	*start_philo_even(void *param);

#endif