/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:38:54 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/06 12:00:03 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static size_t	ft_howmany(char const *s, char c)
{
	size_t	idx;
	size_t	cnt;
	size_t	flag;

	idx = 0;
	cnt = 0;
	flag = 0;
	while (s[idx])
	{
		if (s[idx] != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (s[idx] == c)
			flag = 0;
		idx++;
	}
	return (cnt);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	len;

	printf("whattt!!!\n");

	len = 0;
	while (*s != c || *s)
	{
		s++;
		len++;
	}
	printf("%zu\n",len);
	return (len);
}

static char *ft_dup(const char *c, size_t len)
{
	char	*w_result;

	printf("whattt\n");
	w_result = calloc(sizeof(char), (len + 1));
	if (!(w_result))
		return (NULL);
	while(len--)
		*w_result++ = *c++;
	return (w_result);
}

static void ft_free(char **s, int idx)
{
	while (idx-- > 0)
	{
		free(s[idx]);
		s[idx] = NULL;
	}
	free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	idx;
	size_t	room_size;
	char	**result;

	idx = 0;
	room_size = ft_howmany(s, c);
	if (!(result = calloc(sizeof(char*), (room_size + 1))))
		return (NULL);
	while (*s)
	{
		printf("here\n");
		while (*s == c)
			s++;
		printf("here222\n");	
		result[idx] = ft_dup(s, ft_wordlen(s, c));
		printf("here333\n");	
		s += ft_wordlen(s, c);
		printf("here444\n");	
		if (!result[idx])
		{
			printf("here555\n");	
			ft_free(result, idx);
			return (NULL);
		}
		printf("there\n");

	}
	return (result);
}


int main()
{
	char **result = ft_split("hojin chang is a person", ' ');

	int idx = 0;
	while (*result)
	{
		printf("1. %s\n", result[idx]);
		idx++;
	}
}