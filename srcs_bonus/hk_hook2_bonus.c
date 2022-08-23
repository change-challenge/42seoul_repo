/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hk_hook2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/23 21:21:35 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	hk_key_hook(int keycode, t_game *game)
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
