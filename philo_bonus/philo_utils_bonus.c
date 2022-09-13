/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:06:25 by hchang            #+#    #+#             */
/*   Updated: 2022/09/13 21:20:58 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_print(t_philo *philo, t_info *info, int idx, char *str)
{
	sem_wait(philo->info.sema.print);
	printf("%ld %d %s\n", get_time() - info->birth_t, idx + 1, str);
	if (ft_strstr(str, "is eating"))
	{
		philo->last_eat_t = get_time();
		if (++(philo->eat_cnt) == info->arg.must_eat)
		{
			sem_post(info->sema.eat_checker);
			return ;
		}
	}
	sem_post(philo->info.sema.print);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if ((unsigned char) *s1 != (unsigned char) *s2
			|| *s1 == '\0' || *s2 == '\0')
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_size;

	needle_size = 0;
	while (needle[needle_size])
		needle_size++;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, needle_size) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == ERROR)
		return (ERROR);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	smart_timer(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}
