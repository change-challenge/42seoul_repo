/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:50:05 by hchang            #+#    #+#             */
/*   Updated: 2022/03/09 17:52:23 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%d/n", 123);
	ft_printf("%d/n", 123);


	printf("%5.2s/n", "abcd");
	ft_printf("%5.2d/n", "abcd");

	printf("%5.3s/n", "abcd");
	ft_printf("%5.3s/n", "abcd");

	printf("%5.4s/n", "abcd");
	ft_printf("%5.4s/n", "abcd");

	printf("%5.5s/n", "abcd");
	ft_printf("%5.5s/n", "abcd");
}