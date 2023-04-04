#include "./struct.h"

int	mlx_exit(t_mlx *mlx)
{
	if (mlx->bg.img)
		mlx_destroy_image(mlx->mlx, mlx->bg.img);
	if (mlx->logo.img)
		mlx_destroy_image(mlx->mlx, mlx->logo.img);
	if (mlx->tmp.img)
		mlx_destroy_image(mlx->mlx, mlx->tmp.img);
	if (mlx->title.img)
		mlx_destroy_image(mlx->mlx, mlx->title.img);
	for (int idx = 0; idx < 27; idx++)
	{
		if (mlx->alpha[idx].img)
			mlx_destroy_image(mlx->mlx, mlx->alpha[idx].img);
	}
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->name)
		free(mlx->name);
	if (mlx->box)
		free(mlx->box);
	exit(0);
	return (0);
}

static void	chk_mlx_hook(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_hook, mlx);
	//mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, DESTROYNOTIFY, 0, mlx_exit, mlx);
}

static void	set_box(t_mlx *mlx)
{
	int	idx;
	int	jdx;

	idx = -1;
	mlx->box = (int **)malloc(sizeof(int *) * 9);
	while (++idx < 9)
		mlx->box[idx] = (int *)malloc(sizeof(int) * 2);
	idx = 0;
	while (idx < 3)
	{
		jdx = 0;
		while (jdx < 3)
		{
			mlx->box[jdx + idx * 3][0] = jdx * mlx->win_x / 3;
			mlx->box[jdx + idx * 3][1] = idx * mlx->win_y / 3;
			jdx++;
		}
		idx++;
	}
}

int	display(t_mlx *mlx)
{
	set_box(mlx);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_x, mlx->win_y, "42Jiphyeonjeon");
	mlx->bg.img = mlx_new_image(mlx->mlx, mlx->win_x, mlx->win_y);
	mlx->bg.img_addr = mlx_get_data_addr(mlx->bg.img, &mlx->bg.bpp, &mlx->bg.size_len, &mlx->bg.endian);
	chk_mlx_hook(mlx);
	drawing(mlx);
	mlx_loop_hook(mlx->mlx, &lodding_loop, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
