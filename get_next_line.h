/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:20:19 by hchang            #+#    #+#             */
/*   Updated: 2022/05/10 18:02:49 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#  define FAIL 0
#  define SUCCESS 1
#  define BUFFER_SIZE 4
#ifndef OPEN_MAX
#  define OPEN_MAX 10240
#endif 

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*make_line(t_list **t_back, size_t res_len, char* res);
size_t	check_line(int fd, t_list **t_back, size_t *res_len);
t_list*	read_line(int fd, t_list **t_back, ssize_t *rd);
void	*ft_lstfclean(t_list **lst);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strchr(const char *s, int c, size_t *len);
t_list	*ft_lstnew_add_back(t_list **lst, void *content);
t_list	*ft_lstnew(void *content);




#endif