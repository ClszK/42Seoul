/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 07:19:20 by ljh               #+#    #+#             */
/*   Updated: 2023/12/24 07:13:51 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	    sign;
	int 	r_num;

	sign = 1;
	r_num = 0;
	while ((*(str) >= 9 && *(str) <= 13) || *(str) == 32)
		str++;
	if (*(str) == '-' || *(str) == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (*(str) >= '0' && *(str) <= '9')
	{
		r_num = r_num * 10 + (*(str) - '0');
		str++;
	}
	return (r_num * sign);
}

int	ft_usleep(t_philo *philo, long start, int time)
{
	long			end;

	if (!start || philo_die(philo))
		return (1);
	end = get_ms() - start;
	while ((long)time > end)
	{
		if (philo_die(philo))
			return (1);
		if ((long)time > 10 + end)
			usleep(900);
		else
			usleep(20);
		end = get_ms() - start;
	}
	return (0);
}

long	get_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000);
}

void	philo_fork_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_m); 
	pthread_mutex_unlock(philo->left_m);
}