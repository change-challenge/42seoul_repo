/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:09:11 by hchang            #+#    #+#             */
/*   Updated: 2022/09/13 21:09:06 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*eat_checker(void *param)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)param;
	i = -1;
	while (++i < philo->info.arg.n_philo)
	{
		sem_wait(philo->info.sema.eat_checker);
		if (i + 1 == philo->info.arg.n_philo)
			break ;
		sem_post(philo->info.sema.print);
	}
	i = -1;
	while (++i < philo->info.arg.n_philo)
		kill(philo->info.pid[i], SIGKILL);
	sem_close(philo->info.sema.eat_checker);
	sem_unlink("eat_checker");
	return (NULL);
}

void	init_philo(t_info *info, t_arg *arg, int argc)
{
	sem_unlink("sem_fork");
	info->sema.fork = sem_open("sem_fork", \
		O_CREAT | O_EXCL, 0644, arg->n_philo);
	sem_unlink("sem_print");
	info->sema.print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (argc == 6)
	{
		sem_unlink("eat_checker");
		info->sema.eat_checker = sem_open("eat_checker", \
		O_CREAT | O_EXCL, 0644, 0);
	}
}

void	work(t_philo *philo, pid_t *pid, int argc)
{
	int			idx;
	pthread_t	tid_eatchecker;

	idx = 0;
	philo->info.birth_t = get_time();
	while (idx < philo->info.arg.n_philo)
	{
		pid[idx] = fork();
		if (pid[idx] == 0)
			action(philo);
		philo->idx = ++idx;
	}
	philo->info.pid = pid;
	if (argc == 6)
	{
		pthread_create(&tid_eatchecker, NULL, eat_checker, philo);
		pthread_detach(tid_eatchecker);
	}
	waitpid(-1, 0, 0);
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
		||info->arg.eat_time < 0 || info->arg.sleep_time < 0
		|| info->arg.must_eat < 0)
		return (ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	int			idx;
	pid_t		*pid;
	t_philo		philo;

	idx = -1;
	memset(&philo, 0, sizeof(t_philo));
	if (parse_arg(argc, argv, &philo.info) == ERROR)
		return (ERROR);
	pid = malloc(sizeof(pid_t) * philo.info.arg.n_philo);
	init_philo(&philo.info, &philo.info.arg, argc);
	work(&philo, pid, argc);
	while (++idx < philo.info.arg.n_philo)
		kill(pid[idx], SIGKILL);
	sem_close(philo.info.sema.fork);
	sem_close(philo.info.sema.print);
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	free(pid);
	while (idx--)
		waitpid(-1, 0, 0);
	return (0);
}
