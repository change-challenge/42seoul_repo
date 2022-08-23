/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:25:28 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/23 19:08:19 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
