/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:37 by ljh               #+#    #+#             */
/*   Updated: 2023/12/16 13:53:55 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_ms(void);

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
	(void)memset(pinfo, 0, sizeof(t_pinfo));
}

void	philo_stat_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print_m);
	printf("%lld %d %s", get_ms() - philo->start, philo->philo_idx + 1, str);
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

void	ft_usleep(int time)
{
	struct timeval	ti;
	long long		start;
	long long		end;

	gettimeofday(&ti, NULL);
	start = ti.tv_sec * 1000LL + ti.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&ti, NULL);
		end = ti.tv_sec * 1000LL + ti.tv_usec / 1000;
		if ((long long)time - (end - start) > 10)
			usleep(900);
		else if ((long long)time <= (end - start))
			return ;
		else
			usleep(20);
		// printf("%lld\n", (long long)time - (end - start));
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

void	set_philo(t_pinfo *pinfo)
{
	int		i;
	int		num_fork_philo;
	t_philo	*tmp;

	i = 0;
	tmp = pinfo->philo;
	num_fork_philo = pinfo->info.num_of_philo;
	pthread_mutex_init(&pinfo->print_m, NULL);
	while (i < num_fork_philo)
	{
		(void)memset(&tmp[i], 0, sizeof(t_philo));
		tmp[i].left_fork = &pinfo->fork_stat[i];
		tmp[i].left_m = &pinfo->fork[i];
		tmp[i].right_fork = &pinfo->fork_stat[(i + 1) % num_fork_philo];
		tmp[i].right_m = &pinfo->fork[(i + 1) % num_fork_philo];
		tmp[i].info = &pinfo->info;
		tmp[i].pstate = THINK;
		tmp[i].philo_idx = i;
		tmp[i].print_m = &pinfo->print_m;
		pthread_mutex_init(&tmp[i].start_eat_m, NULL);
		pthread_mutex_init(&tmp[i].alive_m, NULL);
		i++;
	}
}

long long	get_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000);
}

int	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->alive_m);
	if (philo->alive == DIE)
	{
		pthread_mutex_unlock(&philo->alive_m);
		return (-1);
	}
	pthread_mutex_unlock(&philo->alive_m);
	return (1);
}

void	philo_stat_change(t_philo *philo, e_pstat stat)
{
	philo->pstate = stat;
	if (stat == EAT)
		philo_stat_print(philo, "is eating\n");
	else if (stat == SLEEP)
		philo_stat_print(philo, "is sleeping\n");
	else if (stat == THINK)
		philo_stat_print(philo, "is thinking\n");
}

void	philo_think_even(t_philo *philo)
{
	if (philo_die(philo) < 0)
		return ;
	philo_stat_change(philo, THINK);
	while (1)
	{
		usleep(200);
		pthread_mutex_lock(philo->right_m);
		if (*philo->right_fork == 1)
		{
			pthread_mutex_unlock(philo->right_m);
			continue ;
		}
		philo_stat_print(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->left_m);
		if (*philo->left_fork == 1)
		{
			pthread_mutex_unlock(philo->right_m);
			pthread_mutex_unlock(philo->left_m);
			continue ;
		}
		philo_stat_print(philo, "has taken a fork\n");
		*philo->right_fork = 1;
		*philo->left_fork = 1;
		break ;
	}
}

void	philo_think_odd(t_philo *philo)
{
	if (philo_die(philo) < 0)
		return ;
	philo_stat_change(philo, THINK);
	while (1)
	{
		usleep(200);
		pthread_mutex_lock(philo->left_m);
		if (*philo->left_fork == 1)
		{
			pthread_mutex_unlock(philo->left_m);
			continue ;
		}
		philo_stat_print(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_m);
		if (*philo->right_fork == 1)
		{
			pthread_mutex_unlock(philo->left_m);
			pthread_mutex_unlock(philo->right_m);
			continue ;
		}
		philo_stat_print(philo, "has taken a fork\n");
		*philo->right_fork = 1;
		*philo->left_fork = 1;
		break ;
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->start_eat_m);
	philo->start_eat = get_ms();
	pthread_mutex_unlock(&philo->start_eat_m);
	if (philo_die(philo) < 0)
	{
		pthread_mutex_unlock(philo->right_m); 
		pthread_mutex_unlock(philo->left_m);
		return ;
	}
	philo_stat_change(philo, EAT);
	*philo->right_fork = 0;
	*philo->left_fork = 0;
	ft_usleep(philo->info->time_to_eat);
	if (philo->philo_idx % 2 == 1)
	{
		pthread_mutex_unlock(philo->right_m);
		pthread_mutex_unlock(philo->left_m);
	}
	else
	{
		pthread_mutex_unlock(philo->left_m);
		pthread_mutex_unlock(philo->right_m);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (philo_die(philo) < 0)
		return ;
	philo_stat_change(philo, SLEEP);
	ft_usleep(philo->info->time_to_sleep);
}

void	*start_philo(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->philo_idx % 2 == 1 || philo->philo_idx == philo->info->num_of_philo - 1)
		philo_think_even(philo);
	else
	{
		pthread_mutex_lock(philo->left_m);
		pthread_mutex_lock(philo->right_m);
	}
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		if (philo->philo_idx % 2 == 1)
			philo_think_even(philo);
		else
			philo_think_odd(philo);
		if (philo_die(philo) < 0)
			return (NULL);
	}
}

void	create_philo(t_pinfo *pinfo)
{
	int				i;
	long long		start;

	i = 0;
	start = get_ms();
	while (i < pinfo->info.num_of_philo)
	{
		pinfo->philo[i].start = start;
		pthread_create(&pinfo->pthread[i], NULL, start_philo, &pinfo->philo[i]);
		i += 2;
	}
	usleep(200);
	i = 1;
	while (i < pinfo->info.num_of_philo)
	{
		pinfo->philo[i].start = start;
		pthread_create(&pinfo->pthread[i], NULL, start_philo, &pinfo->philo[i]);
		i += 2;
	}
}


int main(int argc, char *argv[])
{
    t_pinfo		pinfo;
	int			i;

	init_pinfo(&pinfo);
    if (argc < 5 || argc > 7 || \
		condition_set(&pinfo.info, argv, argc - 5) < 0 || !create_pinfo(&pinfo))
	{
		clean_pinfo(&pinfo);
        return (1);
	}
	set_philo(&pinfo);
	// printf("num of philo : %d\ntime to die : %d\ntime to eat : %d\ntime to sleep : %d\n", pinfo.philo->info->num_of_philo, pinfo.philo->info->time_to_die, pinfo.philo->info->time_to_eat, pinfo.philo->info->time_to_sleep);
	// for (int a = 0; a < pinfo.info.num_of_philo ; a++)
	// {
	// 	printf("%d's philo\n", pinfo.philo[a].philo_idx);
	// 	printf("%d's left_fork : %d\n", a, *pinfo.philo[a].left_fork);
	// 	printf("%d's left_fork address : %p\n", a, pinfo.philo[a].left_fork);
	// 	printf("%d's right_fork : %d\n",a, *pinfo.philo[a].right_fork);
	// 	printf("%d's right_fork address : %p\n", a, pinfo.philo[a].right_fork);
	// }
	create_philo(&pinfo);
	while (1)
	{
		i = 0;
		while (i < pinfo.info.num_of_philo)
		{
			pthread_mutex_lock(&pinfo.philo[i].start_eat_m);
			if (pinfo.philo[i].start_eat != 0 && get_ms() - pinfo.philo[i].start_eat > (long long)pinfo.info.time_to_die)
			{
				printf("%lld %d died\n", get_ms() - pinfo.philo[i].start, i + 1);
				printf("%lld %lld %d died\n", get_ms() - pinfo.philo[i].start_eat, get_ms() - pinfo.philo[i].start, i + 1);
				i = 0;
				while (i < pinfo.info.num_of_philo)
				{
					pthread_mutex_lock(&pinfo.philo[i].alive_m);
					pinfo.philo[i].alive = DIE;
					pthread_mutex_unlock(&pinfo.philo[i].alive_m);
					i++;
				}
				pthread_mutex_unlock(&pinfo.philo[i].start_eat_m);
				i = -1;
				break ;
			}
			pthread_mutex_unlock(&pinfo.philo[i].start_eat_m);
			i++;
		}
		if (i == -1)
			break ;
		usleep(500);
	}
	for (int x = 0; x < pinfo.info.num_of_philo ; x++)
		pthread_join(pinfo.pthread[x], NULL);
	clean_pinfo(&pinfo);
    return (0);
}