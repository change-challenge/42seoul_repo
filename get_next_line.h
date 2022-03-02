/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:20:19 by hchang            #+#    #+#             */
/*   Updated: 2022/03/02 15:08:45 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#  define ERROR 0
#  define SUCCESS 1
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif 

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

char *get_next_line(int fd);

#endif