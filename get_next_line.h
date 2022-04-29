/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:20:19 by hchang            #+#    #+#             */
/*   Updated: 2022/04/29 17:57:54 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#  define FAIL 0
#  define SUCCESS 1
#  define BUFFER_SIZE 5
#ifndef OPEN_MAX
#  define OPEN_MAX 10240
#endif 


// char *get_next_line(int fd);

#endif