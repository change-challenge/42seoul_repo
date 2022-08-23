/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:24:50 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/23 21:21:46 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	hk_make_rsprite2(t_game *game)
{
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player5.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player7.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player8.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player9.xpm");
}

void	hk_make_rsprite(t_game *game)
{
	t_sprite	*tmp;

	game->r_sprite = malloc(sizeof(t_sprite));
	tmp = game->r_sprite;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player0.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player1.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player3.xpm");
	game->r_sprite->next = malloc(sizeof(t_sprite));
	game->r_sprite = game->r_sprite->next;
	game->r_sprite->img = ft_make_xpm_img(game, "./image/player4.xpm");
	hk_make_rsprite2(game);
	game->r_sprite->next = tmp;
	game->r_sprite = tmp;
}

void	hk_make_lsprite2(t_game *game)
{
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player5.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player4.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player3.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player1.xpm");
}

void	hk_make_lsprite(t_game *game)
{
	t_sprite	*tmp;

	game->l_sprite = malloc(sizeof(t_sprite));
	tmp = game->l_sprite;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player0.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player9.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player8.xpm");
	game->l_sprite->next = malloc(sizeof(t_sprite));
	game->l_sprite = game->l_sprite->next;
	game->l_sprite->img = ft_make_xpm_img(game, "./image/player7.xpm");
	hk_make_lsprite2(game);
	game->l_sprite->next = tmp;
	game->l_sprite = tmp;
}

void	init_sprite(t_game *game)
{
	hk_make_rsprite(game);
	hk_make_lsprite(game);
}
