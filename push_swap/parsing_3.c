/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:44:32 by hchang            #+#    #+#             */
/*   Updated: 2022/07/31 09:55:52 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parsing_split(char *line, char **argv)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, " ");
	free (tmp);
	tmp = line;
	line = ft_strjoin(line, *argv++);
	free (tmp);
	return (line);
}
