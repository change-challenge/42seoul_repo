/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:24:56 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/25 21:32:47 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("ERROR\nTHAT IS WRONG ARGUMENT!", 2);
		exit(0);
	}
	if (hk_window(&game, argv) == 0)
		return (0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 64, \
	game.map.height * 64, "JUNHYUKI IS CHRISTIAN!!");
	start_game(&game);
	mlx_hook(game.win, KEY_EXIT, 0, &destroy_win, &game);
	mlx_hook(game.win, 02, 0, hk_hook, &game);
	mlx_loop_hook(game.mlx, hk_loop_hook, &game);
	mlx_loop(game.mlx);
	free_node(&game);
	return (0);
}
