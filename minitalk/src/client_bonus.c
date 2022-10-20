/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:00:34 by hchang            #+#    #+#             */
/*   Updated: 2022/07/06 20:00:44 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

static pid_t	check_argv(char *pid)
{
	pid_t	s_pid;

	s_pid = ft_atoi(pid);
	if (s_pid < 100 || s_pid > 99998 || !s_pid)
	{
		ft_printf("* ERROR : PID Error\n");
		exit(1);
	}
	return (s_pid);
}

static void	action(int sig)
{
	static int	received_bytes;
	static int	hand_flag;

	if (sig == SIGUSR1)
	{
		if (hand_flag == 0)
			ft_printf("* HandShanking Successe!\n");
		else
			++received_bytes;
		++hand_flag;
	}
	else
	{
		if (hand_flag == 0)
		{
			ft_printf("* ERROR : ");
			exit(1);
		}
		ft_printf("* Received : %d Bytes\n", received_bytes);
		exit(0);
	}
}

static void	hand_shake_check(pid_t pid, unsigned int *hand_flag)
{
	unsigned int	i;

	i = 8;
	while (i--)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("* ERROR : Kill Failed");
			exit(1);
		}
		usleep(30);
	}
	hand_flag++;
}

static void	send_bits(int pid, char *message)
{
	static unsigned int	hand_flag;
	int					msg_idx;
	char				msg_chr;

	if (hand_flag == 0)
		hand_shake_check(pid, &hand_flag);
	while (*message)
	{
		msg_idx = 8;
		msg_chr = *message++;
		while (msg_idx--)
		{
			if (msg_chr >> msg_idx & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	msg_idx = 8;
	while (msg_idx--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		send_bytes;
	pid_t	pid_num;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("* ERROR : Argument Error\n");
		exit(1);
	}
	pid_num = check_argv(argv[1]);
	send_bytes = ft_strlen(argv[2]);
	ft_printf("[Client Sent]\n");
	ft_printf("* pid_num : %d \n* Send : %d Bytes\n", pid_num, send_bytes);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_bits(pid_num, argv[2]);
	while (1)
		pause();
	return (0);
}
