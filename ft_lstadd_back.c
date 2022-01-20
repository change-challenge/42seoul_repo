/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:44:03 by hojinjang         #+#    #+#             */
/*   Updated: 2022/01/19 16:50:55 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
		t_list *tmp;

		tmp = *lst;
		if (new == NULL || lst == NULL)
			return ;
		else if (*lst == NULL)
		{
			*lst = new;
			return ;
		}
		while (*lst->next != NULL)
			*lst = *lst->next;
		*lst->next = new;
		*lst = tmp;
}
