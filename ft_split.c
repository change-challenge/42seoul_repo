/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:38:54 by hojinjang         #+#    #+#             */
/*   Updated: 2021/12/06 14:32:54 by hojinjang        ###   ########.fr       */
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

static size_t	ft_wordlen(char *s, char c)
{
	size_t	len;

	//printf("whattt!!!\n");
	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}

	return (len);
}

static char *ft_dup(char *c, size_t len)
{
	char	*w_result;
	size_t	idx;

	idx = 0;
	w_result = calloc(sizeof(char), (len + 1));
	if (!(w_result))
		return (NULL);
	while(len--)
	{
		w_result[idx] = c[idx];
		idx++;
	}
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
	char	*tmp;
	char	**result;

	idx = 0;
	tmp = (char *)s;
	room_size = ft_howmany(tmp, c);
	//printf("room_size : %zu\n", room_size);
	if (!(result = calloc(sizeof(char*), (room_size + 1))))
		return (NULL);
	while (*tmp)
	{
		//printf("============\n");
		while (*tmp == c)
			tmp++;
		result[idx] = ft_dup(tmp, ft_wordlen(tmp, c));
		tmp += ft_wordlen(tmp, c);
		if (!result[idx])
		{
			ft_free(result, idx);
			return (NULL);
		}
		idx++;
	}
	return (result);
}


int main()
{
	char **result = ft_split("split  ||this|for|me|||||!|", '|');
	//char **result2 = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');

	int idx = 0;
	while (result[idx])
	{
		printf("%s\n",result[idx]);
		idx++;
	}
	//printf("====================================\n");
	idx = 0;
	//while (result2[idx])
	//{
	//	printf("%d. %s\n",idx, result2[idx]);
	//	idx++;
	//}
}