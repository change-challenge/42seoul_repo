/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:24:53 by kyhan             #+#    #+#             */
/*   Updated: 2022/08/25 23:05:07 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../includes/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define KEY_EXIT 17
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_ESC 53
# define KEY_SPACE 49

# define NONE 0
# define LEFT 1
# define RIGHT 2
# define BOTTOM 3
# define TOP 4

# define SUCCESS 1
# define FAIL 0

# define PLAYER 0
# define ENEMY 1

# define ON 0
# define OFF 1

# define EXIST 12

typedef struct s_sprite
{
	void			*img;
	struct s_sprite	*next;
}					t_sprite;

typedef struct s_map
{
	char		**total_map;
	int			width;
	int			height;
	int			p_cnt;
	int			c_cnt;
	int			e_cnt;
	int			enemy_cnt;
}				t_map;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*item;
	void		*player;
	void		*exit;
	void		*cross;
	void		*enemy;
}				t_img;

typedef struct s_enemy
{
	int			x;
	int			y;
}				t_enemy;

typedef struct s_player
{
	int			move_count;
	int			collect;
	int			x;
	int			y;
	int			collect_status;
	int			exit_flag;
	int			move_status;
	int			prev_move_status;
}				t_player;

typedef struct s_game
{
	int			flag;
	int			status;
	int			offset;
	void		*mlx;
	void		*win;
	int			lock;
	int			e_flag;
	t_img		img;
	t_map		map;
	t_player	player;
	t_enemy		enemy;
	t_sprite	*l_sprite;
	t_sprite	*r_sprite;
}				t_game;

int		hk_window(t_game *game, char **argv);
char	*ft_strnstr(const char *hay, const char *nid, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
void	*ft_memset(void *p, int c, size_t len);
void	hk_error(char *str, t_game *game);
int		hk_hook(int keycode, t_game *game);
void	update(t_game *game);
void	success_game(t_game *game);
void	die_game(t_game *game);
void	out_move_cnt(t_game *game);
void	start_game(t_game *game);
void	init_game(t_game *game);
void	init_player(t_game *game);
void	init_sprite(t_game *game);
void	init_enemy(t_game *game);
void	init_img(t_game *game);
void	draw_wall(t_game *game);
void	draw_pce(t_game *game);
void	*ft_make_xpm_img(t_game *game, char *xpmFile);
void	hk_make_rsprite(t_game *game);
void	hk_make_lsprite(t_game *game);
int		destroy_win(t_game *game);
void	left(t_game *game);
void	right(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	move_player(t_game *game);
int		hk_loop_hook(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	check_rec(t_game *game);
void	check_wall(t_game *game);
void	check_pce(t_game *game);
char	*get_line(int fd);
void	free_node(t_game *game);
void	*hk_realloc(void *buf, int before_size, int after_size);
void	update_enemy(t_game *game);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);

#endif
