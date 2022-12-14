/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hk_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojinjang <hojinjang@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/27 03:42:47 by hojinjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	left(t_game *game)
{
	game->flag = LEFT;
	game->lock = ON;
	game->player.prev_move_status = LEFT;
}

void	right(t_game *game)
{
	game->flag = RIGHT;
	game->lock = ON;
	game->player.prev_move_status = RIGHT;
}

void	up(t_game *game)
{
	game->flag = TOP;
	game->lock = ON;
}

void	down(t_game *game)
{
	game->flag = BOTTOM;
	game->lock = ON;
}

int	hk_hook(int keycode, t_game *game)
{
	game->status = ON;
	if (keycode == KEY_ESC)
		destroy_win(game);
	else if (keycode == KEY_A && game->lock == OFF)
		left(game);
	else if (keycode == KEY_D && game->lock == OFF)
		right(game);
	else if (keycode == KEY_S && game->lock == OFF)
		down(game);
	else if (keycode == KEY_W && game->lock == OFF)
		up(game);
	return (0);
}
