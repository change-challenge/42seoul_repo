/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:44:57 by hchang            #+#    #+#             */
/*   Updated: 2022/09/13 21:17:28 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX			2147483647
# define INT_MIN			-2147483648

typedef struct s_status
{
	int	end;
	int	n_full;
}	t_status;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_mutex;

typedef struct s_arg
{
	size_t	die_time;
	int		n_philo;
	int		eat_time;
	int		sleep_time;
	int		must_eat;
}	t_arg;

typedef struct s_info
{
	t_arg		arg;
	t_mutex		mutex;
	t_status	stat;
	size_t		birth_t;
}	t_info;

typedef struct s_philo
{
	int				idx;
	pthread_t		tid;
	int				cnt_eat;
	size_t			last_eat_t;
	t_info			*info;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

enum e_enum
{
	ERROR = -1,
	SUCCESS
};

int			ft_atoi(const char *str);
int			ft_isspace(char c);
size_t		get_t(void);
void		smart_timer(size_t time);
void		mutex_free(t_philo *philo);
int			init_info(t_philo **philo, t_info *info);
int			init_mutex(t_info *info, pthread_mutex_t **fork);
int			init_philo(t_philo **philo, t_info *info, \
			t_arg *arg, pthread_mutex_t *fork);
void		*action(void *param);
char		*ft_strstr(const char *haystack, const char *needle);

#endif