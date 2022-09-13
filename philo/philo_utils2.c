/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:51:26 by hchang            #+#    #+#             */
/*   Updated: 2022/09/13 17:08:27 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_print(t_philo *philo, t_info *info, int idx, char *str)
{
	pthread_mutex_lock(&info->mutex.print);
	if (info->stat.end == 0)
	{
		printf("%ld %d %s\n", get_t() - info->birth_t, idx + 1, str);
		if (strstr(str, "ea"))
		{
			philo->last_eat_t = get_t();
			if (++(philo->cnt_eat) == philo->info->arg.must_eat)
			{
				philo->info->stat.n_full++;
				if (philo->info->stat.n_full == philo->info->arg.n_philo)
					philo->info->stat.end++;
			}
		}
	}
	else
	{
		pthread_mutex_unlock(&info->mutex.print);
		return (ERROR);
	}
	pthread_mutex_unlock(&info->mutex.print);
	return (SUCCESS);
}

int	take_fork(t_philo *philo)
{
	if (philo->idx % 2 == 0)
	{
		pthread_mutex_lock(philo->left);
		if (philo_print(philo, philo->info, \
			philo->idx, "has taken a fork") == ERROR)
			return (ERROR);
		pthread_mutex_lock(philo->right);
		if (philo_print(philo, philo->info, \
			philo->idx, "has taken a fork") == ERROR)
			return (ERROR);
	}
	else
	{
		pthread_mutex_lock(philo->right);
		if (philo_print(philo, philo->info, \
			philo->idx, "has taken a fork") == ERROR)
			return (ERROR);
		pthread_mutex_lock(philo->left);
		if (philo_print(philo, philo->info, \
			philo->idx, "has taken a fork") == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	eating(t_philo *philo, t_arg *arg)
{
	if (philo_print(philo, philo->info, philo->idx, "is eating") == ERROR)
		return (ERROR);
	smart_timer(arg->eat_time);
	return (SUCCESS);
}

int	sleep_thinking(t_philo *philo, t_arg *arg)
{
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	if (philo_print(philo, philo->info, philo->idx, "is sleeping") == ERROR)
		return (ERROR);
	smart_timer(arg->sleep_time);
	if (philo_print(philo, philo->info, philo->idx, "is thinking") == ERROR)
		return (ERROR);
	usleep(10);
	return (SUCCESS);
}

void	*action(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->info->mutex.print);
	philo->last_eat_t = get_t();
	pthread_mutex_unlock(&philo->info->mutex.print);
	if (philo->idx % 2 != 0)
		smart_timer(philo->info->arg.eat_time / 2);
	while (!take_fork(philo)
		&& !eating(philo, &philo->info->arg)
		&& !sleep_thinking(philo, &philo->info->arg));
	return (NULL);
}
