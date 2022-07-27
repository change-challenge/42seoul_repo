/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:38:54 by hojinjang         #+#    #+#             */
/*   Updated: 2022/01/12 16:44:27 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_count(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (s[idx] == c)
			idx++;
		else
		{
			cnt++;
			while (s[idx] && s[idx] != c)
				idx++;
		}
	}
	return (cnt);
}

char	**split_free(char **result, int r_idx)
{
	int	idx;

	idx = 0;
	while (idx < r_idx)
	{
		free(result[idx]);
		idx++;
	}	
	free(result);
	return (result);
}

char	*split_make(char *r_word, char const *base, int b_base, int word_len)
{
	int	idx;

	idx = 0;
	while (word_len > 0)
	{
		r_word[idx] = base[b_base - word_len];
		idx++;
		word_len--;
	}
	r_word[idx] = '\0';
	return (r_word);
}

char	**split_work(char **result, char const *base, char deli, int word_cnt)
{
	int	r_idx;
	int	b_idx;
	int	word_len;

	r_idx = 0;
	b_idx = 0;
	word_len = 0;
	while (base[b_idx] && r_idx < word_cnt)
	{
		while (base[b_idx] && base[b_idx] == deli)
			b_idx++;
		while (base[b_idx] && base[b_idx] != deli)
		{
			b_idx++;
			word_len++;
		}
		result[r_idx] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!(result[r_idx]))
			return (split_free(result, r_idx));
		result[r_idx] = split_make(result[r_idx], base, b_idx, word_len);
		word_len = 0;
		r_idx++;
	}
	result[r_idx] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word_cnt;
	char	**result_split;

	if (s == 0)
		return (NULL);
	word_cnt = split_count(s, c);
	result_split = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!(result_split))
		return (NULL);
	result_split = split_work(result_split, s, c, word_cnt);
	return (result_split);
}
