/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hk_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:14 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/23 21:52:09 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	where_is_collect(t_game *game)
{
	if (game->flag == BOTTOM && game->map.total_map[(game->player.y + 64) / 64] \
	[game->player.x / 64] == 'C')
		game->map.total_map[(game->player.y + 64) / 64] \
		[game->player.x / 64] = 'a';
	else if (game->flag == TOP && game->map.total_map \
	[(game->player.y - 64) / 64][game->player.x / 64] == 'C')
		game->map.total_map[(game->player.y - 64) / 64] \
		[game->player.x / 64] = 'a';
	else if (game->flag == LEFT && game->map.total_map[game->player.y / 64] \
	[(game->player.x - 64) / 64] == 'C')
		game->map.total_map[game->player.y / 64] \
		[(game->player.x - 64) / 64] = 'a';
	else if (game->flag == RIGHT && game->map.total_map[game->player.y / 64] \
	[(game->player.x + 64) / 64] == 'C')
		game->map.total_map[game->player.y / 64] \
		[(game->player.x + 64) / 64] = 'a';
}

void	update(t_game *game)
{
	where_is_collect(game);
	if (game->player.collect == game->map.c_cnt + 1)
		game->player.collect_status = SUCCESS;
	move_player(game);
	if (game->map.total_map[game->player.y / 64][game->player.x / 64] == 'e' \
	|| game->map.total_map[game->player.y / 64][game->player.x / 64] == 'b')
		die_game(game);
	if (game->map.total_map[game->player.y / 64] \
	[game->player.x / 64] == 'E' && game->player.collect_status == SUCCESS)
		success_game(game);
}

void	out_move_cnt(t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->player.move_count);
	mlx_put_image_to_window(game->mlx, game->win, game->img.cross, 0, 0);
	mlx_string_put(game->mlx, game->win, 28, 32, 0, move_count);
	free(move_count);
}
