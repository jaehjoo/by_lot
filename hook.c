#include "./struct.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (mlx->phase == 2)
		return (0);
	if (keycode == ESC_KEY)
		mlx_exit(mlx);
	if (keycode == RTN_KEY)
		drawing(mlx);
	return (0);
}

/*int	mouse_hook(int keycode, t_mlx *mlx)
{
	if (mlx->phase == 2)
		return (0);
	if (keycode == LEFT_CL)
		drawing(mlx);
	return (0);
}*/
