/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:21:20 by hojinjang         #+#    #+#             */
/*   Updated: 2022/01/19 14:27:23 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del == NULL || lst == NULL)
		return ;
	del(lst->content)
	free(lst);
}
