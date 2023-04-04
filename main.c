#include "./struct.h"

static void	init(t_mlx *mlx)
{
	mlx->mlx = 0;
	mlx->win = 0;
	mlx->win_x = 1400;
	mlx->win_y = 800;
	mlx->map_y = 1;
	mlx->name = 0;
	mlx->phase = 0;
}

static int	filename_chk(char *tgt)
{
	int	len;
	int	idx;

	len = 0;
	while (tgt[len])
		len++;
	idx = 4;
	if (tgt[len - idx] == '.')
		idx--;
	if (tgt[len - idx] == 't')
		idx--;
	if (tgt[len - idx] == 'x')
		idx--;
	if (tgt[len - idx] == 't')
		idx--;
	if (!idx)
		return (1);
	return (0);
}

int	err_msg(char *str)
{
	write(2, str, strlen(str));
	return (1);
}

int	main(int ac, char *av[])
{
	t_mlx mlx;

	if (ac != 2)
		return (err_msg("읽을 텍스트 파일 넣어주세요\n"));
	if (filename_chk(av[1]))
	{
		init(&mlx);
		if (txt_to_arr(&mlx, av[1]) || display(&mlx))
			return (1);
	}
	else
		return (err_msg("확장자가 txt인 파일을 넣어주세요\n"));
}
