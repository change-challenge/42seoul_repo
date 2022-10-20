/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:09:13 by hchang            #+#    #+#             */
/*   Updated: 2022/09/13 21:16:35 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>

# define INT_MAX			2147483647
# define INT_MIN			-2147483648

typedef struct s_sem
{
	sem_t	*fork;
	sem_t	*print;
	sem_t	*eat_checker;	
}	t_sem;

typedef struct s_arg
{
	int		die_time;
	int		n_philo;
	int		eat_time;
	int		sleep_time;
	int		must_eat;
}	t_arg;

typedef struct s_info
{
	t_arg		arg;
	t_sem		sema;
	size_t		birth_t;
	pid_t		*pid;
}	t_info;

typedef struct s_philo
{
	int		idx;
	t_info	info;
	size_t	last_eat_t;
	int		eat_cnt;
}	t_philo;

enum e_enum
{
	ERROR = -1,
	SUCCESS
};

int		ft_atoi(const char *str);
size_t	get_time(void);
void	smart_timer(size_t time);
void	philo_print(t_philo *philo, t_info *info, int idx, char *str);
void	action(t_philo *philo);
char	*ft_strstr(const char *haystack, const char *needle);

#endif