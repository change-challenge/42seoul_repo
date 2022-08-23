/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:21:30 by hankyuhong        #+#    #+#             */
/*   Updated: 2022/08/23 21:14:54 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.total_map[i][j] != 'P'
			&& game->map.total_map[i][j] != 'C'
			&& game->map.total_map[i][j] != 'E'
			&& game->map.total_map[i][j] != 'e'
			&& game->map.total_map[i][j] != '0'
			&& game->map.total_map[i][j] != '1')
				hk_error("ERROR\nTHERE IS A NOT VALID CHARACTER!", game);
			j++;
		}
		i++;
	}
}

void	valid_map(t_game *game)
{
	check_valid_char(game);
	check_rec(game);
	check_wall(game);
	check_pce(game);
}

void	map_init(t_game *game, char *line)
{
	game->map.height = 0;
	game->map.width = ft_strlen(line);
	game->map.c_cnt = 0;
	game->map.p_cnt = 0;
	game->map.e_cnt = 0;
	game->map.enemy_cnt = 0;
	game->map.total_map = (char **)calloc(1, (sizeof(char *)));
}

int	map_read(t_game *game, int fd)
{
	char	*line;

	line = get_line(fd);
	if (line == NULL)
		hk_error("ERROR\nNOTHING TO READ IN YOUR MAP!", game);
	map_init(game, line);
	while (line)
	{
		game->map.height++;
		game->map.total_map = (char **)hk_realloc(game->map.total_map, \
		game->map.height - 1, game->map.height);
		game->map.total_map[game->map.height - 1] = line;
		line = get_line(fd);
	}
	valid_map(game);
	return (1);
}

int	hk_window(t_game *game, char **argv)
{
	int	fd;

	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		hk_error("ERROR\nWRONG MAP TITLE", game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		hk_error("ERROR\nFD ERROR !", game);
	if (map_read(game, fd) == 0)
		return (0);
	return (1);
}
