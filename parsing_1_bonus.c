/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:57:33 by hchang            #+#    #+#             */
/*   Updated: 2022/07/31 13:16:13 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	parsing(char ***strs, char **argv)
{
	char	*line;
	int		ret;

	ret = 0;
	line = 0;
	while (*argv)
	{
		if (argv[ret][0] == 0)
			ft_error_null(line);
		if (!line)
			line = ft_strdup(*argv++);
		else
			line = parsing_split(line, argv++);
	}
	*strs = ft_split(line, ' ');
	free (line);
	while ((*strs)[ret])
		ret++;
	return (ret);
}

int	check_sign(char *strs, int *sign)
{
	int				jdx;

	jdx = 0;
	if (strs[0] == '+' && ft_isdigit(strs[1]))
		jdx = 1;
	else if (strs[0] == '-' && ft_isdigit(strs[1]))
	{
		*sign = -1;
		jdx = 1;
	}
	return (jdx);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	ft_error(char **strs)
{
	ft_free(strs);
	ft_putendl_fd("Error", 2);
	exit (1);
}

int	is_dup(int *arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[i] == arr[j])
		{
			free(arr);
			return (1);
		}
		j++;
	}
	return (0);
}
