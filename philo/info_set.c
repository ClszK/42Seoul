/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 07:07:59 by ljh               #+#    #+#             */
/*   Updated: 2023/12/24 07:02:03 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_pinfo(t_pinfo *pinfo)
{
	(void)memset(pinfo, 0, sizeof(t_pinfo));
}

int condition_set(t_condition *info, int argc, char *argv[], int option)
{
    if (argc < 5 || argc > 7)
        return (1);
    info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
    if (option == 1)
	    info->num_of_must_eat = ft_atoi(argv[5]);
    else
        info->num_of_must_eat = 0;
    if (info->num_of_must_eat < 0 || info->time_to_die < 0 || \
        info->time_to_eat < 0 || info->time_to_sleep < 0 || \
        info->num_of_must_eat < 0)
        return (1);
    return (0);
}

int	create_pinfo(t_pinfo *pinfo)
{
	int		num_philo;
	int		i;

	i = -1;
	num_philo = pinfo->info.num_of_philo;
	pinfo->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
											num_philo);
	pinfo->pthread = (pthread_t *)malloc(sizeof(pthread_t) * num_philo);
	pinfo->fork_stat = (int *)malloc(sizeof(int) * num_philo); 
	pinfo->philo = (t_philo *)malloc(sizeof(t_philo) * num_philo);
	if (pinfo->fork == NULL || pinfo->philo == NULL || \
		pinfo->fork_stat == NULL || pinfo->pthread == NULL || \
		!memset(pinfo->fork_stat, 0, sizeof(int) * num_philo) || \
    	pthread_mutex_init(&pinfo->print_m, NULL))
		return (1);
	while (++i < num_philo)
		if (pthread_mutex_init(&pinfo->fork[i], NULL))
			return (1);
	return (0);
}

int	set_philo(t_pinfo *pinfo, t_philo *philo)
{
	int		i;
	int		num_fork_philo;

	i = -1;
	num_fork_philo = pinfo->info.num_of_philo;
	while (++i < num_fork_philo)
	{
		(void)memset(&philo[i], 0, sizeof(t_philo));
		philo[i].left_fork = &pinfo->fork_stat[i];
		philo[i].right_fork = &pinfo->fork_stat[(i + 1) % num_fork_philo];
		philo[i].left_m = &pinfo->fork[i];
		philo[i].right_m = &pinfo->fork[(i + 1) % num_fork_philo];
		philo[i].info = &pinfo->info;
		philo[i].philo_idx = i + 1;
		philo[i].print_m = &pinfo->print_m;
		if (pthread_mutex_init(&philo[i].start_eat_m, NULL) || \
		    pthread_mutex_init(&philo[i].alive_m, NULL))
                return (1);
	}
    return (0);
}

int	create_philo(t_pinfo *pinfo)
{
	int		i;
	int		is_success;
	long	start;

	i = -1;
	start = get_ms();
	while (++i < pinfo->info.num_of_philo)
	{
		pinfo->philo[i].start = start;
		if (i & 1)
			is_success = pthread_create(&pinfo->pthread[i], NULL, start_philo_even, &pinfo->philo[i]);
		else
			is_success = pthread_create(&pinfo->pthread[i], NULL, start_philo_odd, &pinfo->philo[i]);
		if (is_success)
			return (is_success);
	}
	return (0);
}
