/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojin <hchang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:36:09 by hojin             #+#    #+#             */
/*   Updated: 2021/11/09 14:40:08 by hojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int main()
{
	char a[20];

	memset(a, '2', sizeof(a));
	for(int i=0; i< (sizeof(a)/sizeof(char)); i++)
	{ 
	printf("%c\n",a[i]); 
	}
}
