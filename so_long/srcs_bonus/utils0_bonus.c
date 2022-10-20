/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:24:58 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/25 22:33:51 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	*ft_make_xpm_img(t_game *game, char *xpmFile)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, xpmFile, &width, &height);
	if (!img)
	{
		printf ("xpm PATH: %s\n", xpmFile);
		hk_error("ERROR\ncheck xpm PATH or file name", game);
	}
	else if (width != 64 || height != 64)
		hk_error("ERROR\nimg size incorrect", game);
	return (img);
}

void	init_img(t_game *game)
{
	game->img.exit = ft_make_xpm_img(game, "./image/church.xpm");
	game->img.item = ft_make_xpm_img(game, "./image/item.xpm");
	game->img.floor = ft_make_xpm_img(game, "./image/floor.xpm");
	game->img.wall = ft_make_xpm_img(game, "./image/wall.xpm");
	game->img.player = ft_make_xpm_img(game, "./image/player0.xpm");
	game->img.cross = ft_make_xpm_img(game, "./image/cross.xpm");
	game->img.enemy = ft_make_xpm_img(game, "./image/enemy1.xpm");
}

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
