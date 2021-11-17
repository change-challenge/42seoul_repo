/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojin <hojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:00:45 by hojin             #+#    #+#             */
/*   Updated: 2021/11/09 11:01:13 by hojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_isalnum(char c)
{
	if (ft_isdigit(c) && ft_isalpha(c))
		return (1);
	return (0);
}

int	ft_ascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isprint(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}
