/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:20:02 by hchang            #+#    #+#             */
/*   Updated: 2022/03/01 21:57:33 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 삭제할 헤더
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	char *result;
	
	result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	return (result);
}

int main() 
{ 
	int fd;
	int i;
	int j;
	
	char *line = 0;
	char *lineadress[66]; 
	j = 1;
	
	printf("\n==========================================\n");
	printf("========= TEST 2 : Empty Lines ===========\n"); 
	printf("==========================================\n\n"); 
	
	if (!(fd = open("/a.txt", O_RDONLY))) 
	{
		printf("\nError in open\n");
		return (0);
	} 
	
	while ((line = get_next_line(fd)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	} 
	printf("|%s\n", line);
	free(line);
	close(fd);
}