/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hk_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/23 21:55:54 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move(t_game *game)
{
	game->player.prev_y = game->player.y;
	game->player.prev_x = game->player.x;
	if (game->lock == ON)
		game->player.move_count++;
}

int	hk_hook2(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_win(game);
	else if (keycode == KEY_A && game->lock == OFF)
		left(keycode, game);
	else if (keycode == KEY_D && game->lock == OFF)
		right(keycode, game);
	else if (keycode == KEY_S && game->lock == OFF)
		down(keycode, game);
	else if (keycode == KEY_W && game->lock == OFF)
		up(keycode, game);
	else
		game->player.move_status = NONE;
	return (0);
}

int	hk_hook(int keycode, t_game *game)
{
	game->status = ON;
	hk_hook2(keycode, game);
	move(game);
	return (0);
}
