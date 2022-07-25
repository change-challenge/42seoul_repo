/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:21:48 by kyhan             #+#    #+#             */
/*   Updated: 2022/07/25 14:26:47 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_get_line(char *buffer);
char	*ft_save(char *buffer);
char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);
size_t	ft_strlen_g(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strchr_g(char *s, int c);

#endif
