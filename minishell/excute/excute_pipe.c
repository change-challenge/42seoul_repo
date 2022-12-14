/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:16:02 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/15 18:55:21 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_child_proc(t_info *info, t_tree *myself, t_ftool *tool, int index)
{
	if (!index)
	{
		dup2(tool->p_fd[1], STDOUT_FILENO);
		close(tool->p_fd[1]);
		close(tool->p_fd[0]);
		tool->status = execute(info, myself->left_child);
		exit(tool->status);
	}
	else if (index == 1)
	{
		tool->status = execute(info, myself->right_child);
		exit(tool->status);
	}
}

void	pipe_parent_proc(pid_t *left, pid_t *right, t_ftool *tool, int index)
{
	if (!index)
	{
		*left = tool->pid;
		dup2(tool->p_fd[0], STDIN_FILENO);
		close(tool->p_fd[0]);
		close(tool->p_fd[1]);
	}
	else if (index == 1)
		*right = tool->pid;
}

int	execute_pipe(t_info *info, t_tree *myself)
{
	int		i;
	int		in_fd;
	pid_t	left;
	pid_t	right;
	t_ftool	tool;

	in_fd = dup(STDIN_FILENO);
	pipe(tool.p_fd);
	i = 0;
	while (i < 2)
	{
		tool.pid = fork();
		if (!tool.pid)
			pipe_child_proc(info, myself, &tool, i);
		else
			pipe_parent_proc(&left, &right, &tool, i);
		i++;
	}
	dup2(in_fd, STDIN_FILENO);
	waitpid(left, &tool.status, 0);
	waitpid(right, &tool.status, 0);
	close(in_fd);
	return (WEXITSTATUS(tool.status));
}
