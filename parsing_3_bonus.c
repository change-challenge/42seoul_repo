/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:43:36 by hchang            #+#    #+#             */
/*   Updated: 2022/07/28 18:47:48 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parsing_split(char *tmp, char *line, char **argv)
{
	tmp = line;
	line = ft_strjoin(line, " ");
	free (tmp);
	tmp = line;
	line = ft_strjoin(line, *argv++);
	free (tmp);
}
