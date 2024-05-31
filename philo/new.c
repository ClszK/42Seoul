/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 03:26:43 by ljh               #+#    #+#             */
/*   Updated: 2023/12/24 07:24:03 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_stat_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print_m);
	printf("%ld %d %s", get_ms() - philo->start, philo->philo_idx, str);
	pthread_mutex_unlock(philo->print_m);
}

void	clean_pinfo(t_pinfo *pinfo)
{
	int	i;

	i = 0;
	if (pinfo->fork_stat)
		free(pinfo->fork_stat);
	if (pinfo->pthread)
		free(pinfo->pthread);
	if (pinfo->philo)
		free(pinfo->philo);
	if (pinfo->fork)
	{
		while (i < pinfo->info.num_of_philo)
		{
			if (pthread_mutex_destroy(&pinfo->fork[i]) == EBUSY)
				printf("%d is mutex lock.\n", i);
			i++;
		}
		free(pinfo->fork);
	}
}

int	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->alive_m);
	if (philo->alive == DIE)
	{
		pthread_mutex_unlock(&philo->alive_m);
		return (1);
	}
	pthread_mutex_unlock(&philo->alive_m);
	return (0);
}

long	philo_stat_change(t_philo *philo, int stat)
{
	if (philo_die(philo))
	{
		pthread_mutex_unlock(philo->print_m);
		return (0);
	}
	if (stat == EAT)
		philo_stat_print(philo, "is eating\n");
	else if (stat == SLEEP)
		philo_stat_print(philo, "is sleeping\n");
	else if (stat == THINK)
		philo_stat_print(philo, "is thinking\n");
	else if (stat == FORK)
		philo_stat_print(philo, "has taken a fork\n");
	return (get_ms());
}

int	philo_think_even(t_philo *philo)
{
	if (!philo_stat_change(philo, THINK))
		return (1);
	usleep(500);
	pthread_mutex_lock(philo->right_m);
	if (!philo_stat_change(philo, FORK))
	{
		pthread_mutex_unlock(philo->right_m);
		return (1);
	}
	pthread_mutex_lock(philo->left_m);
	if (!philo_stat_change(philo, FORK))
	{
		philo_fork_down(philo);
		return (1);
	}
	*philo->right_fork = 1;
	*philo->left_fork = 1;
	return (0);
}

int	philo_think_odd(t_philo *philo)
{
	if (!philo_stat_change(philo, THINK))
		return (1);
	usleep(1000);
	pthread_mutex_lock(philo->left_m);
	if (!philo_stat_change(philo, FORK))
	{
		pthread_mutex_unlock(philo->left_m);
		return (1);
	}
	pthread_mutex_lock(philo->right_m);
	if (!philo_stat_change(philo, FORK))
	{
		philo_fork_down(philo);
		return (1);
	}
	*philo->right_fork = 1;
	*philo->left_fork = 1;
	return (0);
}

int	philo_eat(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->start_eat_m);
	if (get_ms() - philo->start_eat > philo->info->time_to_die)
	{
		pthread_mutex_unlock(&philo->start_eat_m);
		philo_fork_down(philo);
		return (1);
	}
	philo->start_eat = philo_stat_change(philo, EAT);
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->start_eat_m);
	time = philo->start_eat;
	if (ft_usleep(philo, time, philo->info->time_to_eat))
	{
		philo_fork_down(philo);
		return (1);
	}
	*philo->right_fork = 0;
	*philo->left_fork = 0;
	philo_fork_down(philo);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	long	time;

	time = philo_stat_change(philo, SLEEP);
	if (ft_usleep(philo, time, philo->info->time_to_sleep))
		return (1);
	return (0);
}

void	*start_philo_odd(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->start_eat_m);
	philo->start_eat = get_ms();
	pthread_mutex_unlock(&philo->start_eat_m);
	if (philo->philo_idx == philo->info->num_of_philo)
	{
		if (philo_think_odd(philo))
			return (NULL);
	}
	else
	{
		pthread_mutex_lock(philo->left_m);
		pthread_mutex_lock(philo->right_m);
	}
	while (1)
	{
		if (philo_eat(philo) || \
			philo_sleep(philo) || \
			philo_think_odd(philo))
			return (NULL);
	}
	return (NULL);
}

void	*start_philo_even(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->start_eat_m);
	philo->start_eat = get_ms();
	pthread_mutex_unlock(&philo->start_eat_m);
	philo_think_even(philo);
	while (1)
	{
		if (philo_eat(philo) || \
			philo_sleep(philo) || \
			philo_think_even(philo))
			return (NULL);
	}
	return (NULL);
}