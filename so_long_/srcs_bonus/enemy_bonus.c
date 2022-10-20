/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:27:37 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/25 21:11:08 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_enemy(t_game *game)
{
	int	i;
	int	j;

	i = game->player.y / 64;
	while (i < game->map.height)
	{
		j = game->player.x / 64;
		while (j < game->map.width)
		{
			if (game->map.total_map[i][j] == 'e')
			{
				game->e_flag = EXIST;
				game->enemy.x = j;
				game->enemy.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	update_enemy(t_game *game)
{
	init_enemy(game);
	if (game->e_flag == EXIST)
	{
		if (game->map.total_map[game->enemy.y + 1][game->enemy.x] == '0')
		{
			game->map.total_map[game->enemy.y][game->enemy.x] = '0';
			game->map.total_map[game->enemy.y + 1][game->enemy.x] = 'b';
		}
		else if (game->map.total_map[game->enemy.y][game->enemy.x + 1] == '0')
		{
			game->map.total_map[game->enemy.y][game->enemy.x] = '0';
			game->map.total_map[game->enemy.y][game->enemy.x + 1] = 'b';
		}
		else if (game->map.total_map[game->enemy.y - 1][game->enemy.x] == '0')
		{
			game->map.total_map[game->enemy.y][game->enemy.x] = '0';
			game->map.total_map[game->enemy.y - 1][game->enemy.x] = 'b';
		}
		else if (game->map.total_map[game->enemy.y][game->enemy.x - 1] == '0')
		{
			game->map.total_map[game->enemy.y][game->enemy.x] = '0';
			game->map.total_map[game->enemy.y][game->enemy.x - 1] = 'b';
		}
	}
}
