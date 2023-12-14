/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:37 by ljh               #+#    #+#             */
/*   Updated: 2023/12/15 05:58:46 by ljh              ###   ########.fr       */
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
	(void)memset(pinfo, 0, sizeof(t_philo));
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
			if (pthread_mutex_destroy(&pinfo->pstat_m[i]) == EBUSY)
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
	pinfo->pstat_m = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
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
		if (pthread_mutex_init(&pinfo->pstat_m[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

void	set_philo(t_pinfo *pinfo)
{
	int		i;
	int		num_fork_philo;
	t_philo	*tmp;

	i = 0;
	tmp = pinfo->philo;
	num_fork_philo = pinfo->info.num_of_philo;
	while (i < num_fork_philo)
	{
		(void)memset(&tmp[i], 0, sizeof(t_philo));
		tmp[i].left_fork = &pinfo->fork_stat[i];
		tmp[i].left_m = &pinfo->fork[i];
		tmp[i].right_fork = &pinfo->fork_stat[(i + 1) % num_fork_philo];
		tmp[i].left_m = &pinfo->fork[(i + 1) % num_fork_philo];
		tmp->info = &pinfo->info;
		tmp[i].pstate = THINK;
		tmp[i].pstate_m = &pinfo->pstat_m[i];
		tmp[i].philo_idx = i;
		i++;
	}
}

// void	*start_philo(void *param)
// {

// }

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
	set_philo(&pinfo);
	pinfo.fork_stat[1] = 1;
	for (int x = 0; x < pinfo.info.num_of_philo ; x++)
	{
		printf("%d's philo\n", pinfo.philo[x].philo_idx);
		printf("%d's left_fork : %d\n", x, *pinfo.philo[x].left_fork);
		printf("%d's right_fork : %d\n",x, *pinfo.philo[x].right_fork);
	}
	
    return (0);
}