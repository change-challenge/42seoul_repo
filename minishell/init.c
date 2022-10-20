/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:13:42 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/15 18:54:55 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

void	init_info(t_info *info)
{
	info->double_quote_flag = 0;
	info->quote_flag = 0;
	info->redir_out_flag = 0;
	info->redir_in_flag = 0;
	info->redir_cnt = 0;
	info->tmp_fd = 0;
	info->hd_cnt = 0;
	info->dlist = 0;
	info->fo.i = 0;
	info->fo.last_idx = 0;
	info->root = 0;
	info->err_flag = 0;
	info->path_flag = 0;
}

int	init_env(t_info *info)
{
	int	i;

	i = 0;
	info->env = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], "OLDPWD=", 7) && ++i)
			continue ;
		add_list(&info->env, environ[i]);
		i++;
	}
	rl_catch_signals = 0;
	return (0);
}
