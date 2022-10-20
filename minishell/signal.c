/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:14:03 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/15 13:28:16 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_exit_code = 1;
	}
}

void	signal_handler2(int signal)
{
	if (signal == SIGINT)
	{
		g_exit_code = 130;
		printf("\n");
	}
	else if (signal == SIGQUIT)
	{
		g_exit_code = 131;
		printf("^\\Quit: 3\n");
	}
}

void	set_signal_handler(int flag)
{
	if (!flag)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
	}
	else
	{
		signal(SIGQUIT, signal_handler2);
		signal(SIGINT, signal_handler2);
	}
}

void	hd_sig(int signum)
{
	exit(1);
}

void	set_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
