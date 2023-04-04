#include "./struct.h"

static int	add_line(t_mlx *mlx, char *line)
{
	int		y;
	char	**map;

	map = (char **)malloc(sizeof(char *) * ((mlx->map_y) + 1));
	if (!map)
		return (0);
	y = mlx->map_y - 1;
	map[y] = strdup(line);
	if (!map[y])
		return (0);
	if (mlx->name)
	{
		while (--y >= 0)
			map[y] = mlx->name[y];
		free(mlx->name);
	}
	mlx->name = map;
	mlx->name[mlx->map_y] = 0;
	return (1);
}

int	txt_to_arr(t_mlx *mlx, char	*str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line <= 0)
			break ;
		if (line[0] != 0)
			if (!add_line(mlx, line))
				return (err_msg("말록 에러네요. 안타깝게 되었습니다.\n"));
		(mlx->map_y)++;
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
