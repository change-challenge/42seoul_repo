/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hk_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/25 22:40:11 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	left(int keycode, t_game *game)
{
	(void)keycode;
	game->player.move_status = LEFT;
	game->flag = LEFT;
	game->lock = ON;
	game->player.prev_move_status = LEFT;
}

void	right(int keycode, t_game *game)
{
	(void)keycode;
	game->flag = RIGHT;
	game->player.move_status = RIGHT;
	game->lock = ON;
	game->player.prev_move_status = RIGHT;
}

void	up(int keycode, t_game *game)
{
	(void)keycode;
	game->flag = TOP;
	game->lock = ON;
}

void	down(int keycode, t_game *game)
{
	(void)keycode;
	game->flag = BOTTOM;
	game->lock = ON;
}

int	hk_hook(int keycode, t_game *game)
{
	game->status = ON;
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
	if (game->lock == ON)
		game->player.move_count++;
	return (0);
}
