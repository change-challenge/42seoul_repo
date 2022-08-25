/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:24:58 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/25 21:11:44 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	die_game(t_game *game)
{
	hk_error("You died", game);
}

void	success_game(t_game *game)
{
	game->player.exit_flag = SUCCESS;
	hk_error("SUCCESS", game);
}

int	destroy_win(t_game *game)
{
	hk_error("The End", game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
