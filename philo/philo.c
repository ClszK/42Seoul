/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:37 by ljh               #+#    #+#             */
/*   Updated: 2023/12/24 07:14:38 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
    t_pinfo		pinfo;
	int			i;
	int			pos;
	int			stop;

	init_pinfo(&pinfo);
    if (condition_set(&pinfo.info, argc, argv, argc - 5) || \
		create_pinfo(&pinfo) || set_philo(&pinfo, pinfo.philo) || \
		create_philo(&pinfo)
		)
	{
		clean_pinfo(&pinfo);
        return (1);
	}
	while (1)
	{
		i = 0;
		stop = 0;
		while (i < pinfo.info.num_of_philo)
		{
			pthread_mutex_lock(&pinfo.philo[i].start_eat_m);
			if (pinfo.info.num_of_must_eat && pinfo.philo[i].eat_cnt < pinfo.info.num_of_must_eat)
				stop = 1;
			if (pinfo.philo[i].start_eat != 0 && get_ms() - pinfo.philo[i].start_eat > (long)pinfo.info.time_to_die)
			{
				pos = i;
				i = 0;
				while (i < pinfo.info.num_of_philo)
				{
					pthread_mutex_lock(&pinfo.philo[i].alive_m);
					pinfo.philo[i].alive = DIE;
					pthread_mutex_unlock(&pinfo.philo[i].alive_m);
					i++;
				}
				pthread_mutex_lock(&pinfo.print_m);
				printf("%ld %d died\n", get_ms() - pinfo.philo[pos].start, pos + 1);
				printf("%ld %ld %d died\n", get_ms() - pinfo.philo[pos].start_eat, get_ms() - pinfo.philo[pos].start, pos + 1);
				pthread_mutex_unlock(&pinfo.print_m);
				pthread_mutex_unlock(&pinfo.philo[i].start_eat_m);
				i = -1;
				break ;
			}
			pthread_mutex_unlock(&pinfo.philo[i].start_eat_m);
			i++;
		}
		if (i == -1)
			break ;
		if (pinfo.info.num_of_must_eat && stop == 0)
		{
			i = 0;
			while (i < pinfo.info.num_of_philo)
			{
				pthread_mutex_lock(&pinfo.philo[i].alive_m);
				pinfo.philo[i].alive = DIE;
				pthread_mutex_unlock(&pinfo.philo[i].alive_m);
				i++;
			}
			break ;
		}
		usleep(500);
	}
	for (int x = 0; x < pinfo.info.num_of_philo ; x++)
		pthread_join(pinfo.pthread[x], NULL);
	clean_pinfo(&pinfo);
    return (0);
}
