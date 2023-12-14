/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:37 by ljh               #+#    #+#             */
/*   Updated: 2023/12/14 01:24:28 by ljh              ###   ########.fr       */
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

int    condition_set(t_condition *info, char *argv[], int option)
{
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
        return (-1);
    return (1);
}

void	init_pinfo(t_pinfo *pinfo)
{
	pinfo->fork = NULL;
	pinfo->fork_stat = NULL;
	pinfo->philo = NULL;
	pinfo->pthread = NULL;
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

int	create_pinfo(t_pinfo *pinfo)
{
	int		num_philo;
	int		i;

	i = 0;
	num_philo = pinfo->info.num_of_philo;
	pinfo->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
											num_philo);
	pinfo->pthread = (pthread_t *)malloc(sizeof(pthread_t) * num_philo);	
	pinfo->fork_stat = (int *)malloc(sizeof(int) * num_philo); 
	pinfo->philo = (t_philo *)malloc(sizeof(t_philo) * num_philo);
	if (pinfo->fork == NULL || pinfo->philo == NULL || \
		pinfo->fork_stat == NULL || pinfo->pthread == NULL || \
		memset(pinfo->fork_stat, 0, sizeof(int) * num_philo) == NULL)
		return (0);
	while (i < num_philo)
	{
		if (pthread_mutex_init(&pinfo->fork[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	pthread_t	*pthread;
    t_pinfo		pinfo;

	init_pinfo(&pinfo);
    if (argc < 5 || argc > 7 || \
		condition_set(&pinfo.info, argv, argc - 5) < 0 || !create_pinfo(&pinfo))
	{
		clean_pinfo(&pinfo);
        return (1);
	}
	
    return (0);
}