#include "so_long.h"


int	hk_window_size(int fd, int *col)
{
	char	*row;
	int		row_size;
	int		tmp;
	// map check!
	row = get_next_line(fd);
	tmp = ft_strlen(row);
	*col = 0;
	while (row)
	{
		row_size = ft_strlen(row);
		if (row_size != tmp)
			//error
		tmp = row_size;
		row = get_next_line(fd);
		(*col)++;
	}
	return (row_size);
}

void	hk_window(t_game *game, char **argv)
{
	int fd;
	int	col;
	
	fd = open(argv[1], O_RDONLY); // fd 안 닫아도 됨 
	//if (fd < 0)
		//error
	//if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		//error
	game->map.row = hk_window_size(fd, &col) * 64;
	//if (col <= 1)
		// error
	game->map.col = col * 64;
}


