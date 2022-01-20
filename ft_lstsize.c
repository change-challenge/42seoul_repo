/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:32:49 by hojinjang         #+#    #+#             */
/*   Updated: 2022/01/19 11:40:19 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int cnt;

	cnt = 0;
	while (lst)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
