/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:45:25 by hchang            #+#    #+#             */
/*   Updated: 2022/09/13 22:18:46 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_t(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == ERROR)
		return (ERROR);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	smart_timer(size_t time)
{
	size_t	start;

	start = get_t();
	while (get_t() - start < time)
		usleep(100);
}

void	mutex_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->arg.n_philo)
		pthread_mutex_destroy(philo[i].left);
	pthread_mutex_destroy(&philo->info->mutex.print);
	free(philo[0].left);
	free(philo);
}

int	ft_atoi(const char *str)
{
	int		idx;
	long	minus;
	long	result;

	idx = 0;
	result = 0;
	minus = 1;
	while (ft_isspace(str[idx]))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			minus *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result = (result * 10) + (str[idx] - '0');
		if (result > 2147483647 && minus == 1)
			return (-1);
		if (result > 2147483648 && minus == -1)
			return (0);
		idx++;
	}
	return (minus * result);
}

int	init_info(t_philo **philo, t_info *info)
{
	pthread_mutex_t	*fork;

	info->stat.end = 0;
	info->stat.n_full = 0;
	if (init_mutex(info, &fork) == ERROR)
		return (ERROR);
	if (init_philo(philo, info, &info->arg, fork) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
