/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:44:55 by hchang            #+#    #+#             */
/*   Updated: 2022/09/13 22:15:49 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo **philo, t_info *info, t_arg *arg, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	(*philo) = malloc(sizeof(t_philo) * arg->n_philo);
	if (*philo == NULL)
		return (ERROR);
	while (i < arg->n_philo)
	{
		(*philo)[i].idx = i;
		(*philo)[i].cnt_eat = 0;
		(*philo)[i].info = info;
		(*philo)[i].left = &fork[i];
		(*philo)[i].right = &fork[(i + 1) % arg->n_philo];
		(*philo)[i].last_eat_t = get_t();
		++i;
	}
	i = -1;
	pthread_mutex_lock(&info->mutex.print);
	while (++i < arg->n_philo)
		if (pthread_create(&(*philo)[i].tid, NULL, action, &(*philo)[i]))
			return (ERROR);
	info->birth_t = get_t();
	pthread_mutex_unlock(&info->mutex.print);
	return (SUCCESS);
}

int	init_mutex(t_info *info, pthread_mutex_t **fork)
{
	int	i;

	i = 0;
	*fork = malloc(sizeof(pthread_mutex_t) * info->arg.n_philo);
	if (!(*fork))
		return (ERROR);
	while (i < info->arg.n_philo)
		if (pthread_mutex_init(&(*fork)[i++], PTHREAD_MUTEX_NORMAL) != 0)
			return (ERROR);
	if (pthread_mutex_init(&info->mutex.print, PTHREAD_MUTEX_NORMAL) != 0)
		return (ERROR);
	return (SUCCESS);
}

int	parse_arg(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (ERROR);
	info->arg.n_philo = ft_atoi(argv[1]);
	info->arg.die_time = ft_atoi(argv[2]);
	info->arg.eat_time = ft_atoi(argv[3]);
	info->arg.sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->arg.must_eat = ft_atoi(argv[5]);
		if (info->arg.must_eat == 0)
			return (ERROR);
	}
	else
		info->arg.must_eat = 0;
	if (info->arg.n_philo <= 0 || info->arg.die_time <= 0
		|| info->arg.eat_time < 0 || info->arg.sleep_time < 0
		|| info->arg.must_eat < 0)
		return (ERROR);
	return (SUCCESS);
}

void	monitor(t_philo *philo, t_info *info)
{
	int	i;
	int	kill_;

	kill_ = 0;
	while (1)
	{
		i = 0;
		while (i < info->arg.n_philo)
		{
			pthread_mutex_lock(&philo->info->mutex.print);
			kill_ = info->stat.end;
			if (get_t() - philo[i].last_eat_t > info->arg.die_time)
			{
				info->stat.end++;
				printf("%ld %d died\n", get_t() - info->birth_t - 1, i + 1);
				pthread_mutex_unlock(&philo->info->mutex.print);
				return ;
			}
			else
				pthread_mutex_unlock(&philo->info->mutex.print);
			if (kill_)
				return ;
			++i;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	t_philo	*philo;

	if (parse_arg(argc, argv, &info) == ERROR)
		return (ERROR);
	if (init_info(&philo, &info) == SUCCESS)
		monitor(philo, philo->info);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_mutex_unlock(philo[i].left);
	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_join(philo[i].tid, NULL);
	mutex_free(philo);
	return (0);
}
