/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:44:32 by hchang            #+#    #+#             */
/*   Updated: 2022/07/28 19:08:14 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_split(char *line, char **argv)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, " ");
	free (tmp);
	tmp = line;
	line = ft_strjoin(line, *argv++);
	free (tmp);
}
