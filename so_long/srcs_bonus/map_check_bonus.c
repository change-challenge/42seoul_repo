/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:05 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/25 21:11:35 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_rec(t_game *game)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = ft_strlen(game->map.total_map[i]);
	while (i < game->map.height)
	{
		if (tmp != ft_strlen(game->map.total_map[i]))
			hk_error("ERROR\nTHAT IS NOT RECTAGLE MAP!", game);
		i++;
	}
}

void	check_wall_option(t_game *game, int height, int width)
{
	while (height < game->map.height)
	{
		width = 0;
		if (height == 0 || height == game->map.height - 1)
		{
			while (width < game->map.width && \
			(!height || height == game->map.height - 1))
			{
				if (game->map.total_map[height][width] != '1')
				{
					hk_error("ERROR\nWALL IS NOT SURROUND BY \
					WALL - width", game);
					break ;
				}
				width++;
			}
		}
		else if (game->map.total_map[height][0] != '1' || \
		game->map.total_map[height][game->map.width - 1] != '1')
		{
			hk_error("ERROR\nWALL IS NOT SURROUND BY WALL - height", game);
			break ;
		}
		height++;
	}
}

void	check_wall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	check_wall_option(game, height, width);
}

void	count_pce(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.total_map[i][j] == 'P')
				game->map.p_cnt++;
			else if (game->map.total_map[i][j] == 'C')
				game->map.c_cnt++;
			else if (game->map.total_map[i][j] == 'E')
				game->map.e_cnt++;
			else if (game->map.total_map[i][j] == 'e')
				game->map.enemy_cnt++;
			j++;
		}
		i++;
	}
}

void	check_pce(t_game *game)
{
	count_pce(game);
	if (game->map.p_cnt != 1)
		hk_error("ERROR\nWe need only one player", game);
	else if (game->map.c_cnt < 1)
		hk_error("ERROR\nat least 1 collect", game);
	else if (game->map.e_cnt < 1)
		hk_error("ERROR\nat least 1 exit", game);
}
