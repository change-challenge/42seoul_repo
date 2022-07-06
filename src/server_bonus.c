/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:01:00 by hchang            #+#    #+#             */
/*   Updated: 2022/07/06 20:01:06 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

static int	check_pid(siginfo_t *info, unsigned int *i, unsigned char *c)
{
	static pid_t	client_pid;

	client_pid = 0;
	if (!client_pid)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		if (kill(client_pid, SIGUSR2) == -1 \
			|| kill(info->si_pid, SIGUSR2) == -1)
			ft_printf("* Error : PID Differenet!\n");
		*i = 0;
		*c = 0;
	}
	return (client_pid);
}

static void	when_you_received(pid_t *client_pid, unsigned int *msg_idx, \
	unsigned char *msg_chr)
{
	static unsigned int		hand_flag;

	*msg_idx = 0;
	if (*msg_chr == 0b11111111)
	{
		hand_flag++;
		ft_printf("* HandShanking Successe!\n");
	}
	else if (hand_flag > 0)
	{
		if (!*msg_chr)
		{
			kill(*client_pid, SIGUSR2);
			*client_pid = 0;
			write(1, "\n", 1);
			*msg_chr = 0;
			return ;
		}
		ft_printf("%c", *msg_chr);
	}
	*msg_chr = 0;
	kill(*client_pid, SIGUSR1);
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static unsigned int		msg_idx;
	static pid_t			client_pid;
	static unsigned char	msg_chr;

	(void)context;
	client_pid = check_pid(info, &msg_idx, &msg_chr);
	msg_chr |= (sig == SIGUSR2);
	if (++msg_idx == 8)
		when_you_received(&client_pid, &msg_idx, &msg_chr);
	else
		msg_chr <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("[Server PID : %d]\n", getpid());
	sigemptyset(&s_sigaction.sa_mask);
	sigaddset(&s_sigaction.sa_mask, SIGUSR1);
	sigaddset(&s_sigaction.sa_mask, SIGUSR2);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
