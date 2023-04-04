#include "./struct.h"

static double	get_radian(int num)
{
	return (num * 3.14159265 / 180);
}

void	put_pixel(t_mlx *mlx, int x, int y, int color, t_img *img)
{
	char	*dest;

	if (0 < x && x < mlx->win_x && 0 < y && y < mlx->win_y)
	{
		dest = img->img_addr + (y * img->size_len + x * (img->bpp / 8));
		*(unsigned int *)dest = color;
	}
}

static void	clear_image(t_mlx *mlx, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->win_y)
	{
		x = 0;
		while (x < mlx->win_x)
		{
			put_pixel(mlx, x, y, color, &mlx->bg);
			x++;
		}
		y++;
	}
}

static void	init_file(t_mlx *mlx)
{
	char	alpha[27] = "abcdefghijklmnopqrstuvwxyz";
	char	data[15] = "./data/little/";
	char	file[6] = " .xpm";
	char	*tmp;

	mlx->logo.img = mlx_xpm_file_to_image(mlx->mlx, "./data/little/jiphyeonjeon_logo.xpm", &mlx->logo.width, &mlx->logo.height);
	for (int idx = 0; idx < 27; idx++)
	{
		file[0] = alpha[idx];
		tmp = ft_strjoin(data, file);
		mlx->alpha[idx].img = mlx_xpm_file_to_image(mlx->mlx, tmp, &mlx->alpha[idx].width, &mlx->alpha[idx].height);
		free(tmp);
	}
}

static void	input_str(t_mlx *mlx, char *tgt, int x, int y)
{
	int	len;
	int	idx;

	len = strlen(tgt);
	for (idx = 0; idx < len; idx++)
	{
		if ('a' <= tgt[idx] && tgt[idx] <= 'z')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->alpha[(int)tgt[idx] - 97].img, x + mlx->alpha[(int)tgt[idx] - 97].width * idx, y + mlx->win_y / 9);
	}
}

static void	draw_title(t_mlx *mlx)
{
	int	width;
	int	height;

	mlx->title.img = mlx_xpm_file_to_image(mlx->mlx, "./data/background/gyeongbokgeung_korea.xpm", &mlx->title.width, &mlx->title.height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->title.img, mlx->box[0][0], mlx->box[0][1]);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->logo.img, mlx->box[0][0] + mlx->win_x / 12, mlx->box[0][1] + mlx->win_y / 16);
	input_str(mlx, "lucky reviewer", mlx->box[0][0] + mlx->logo.width + mlx->win_x / 8, mlx->box[0][1] + mlx->win_y / 64);
	mlx->tmp.img = mlx_xpm_file_to_image(mlx->mlx, "./data/little/start.xpm", &mlx->tmp.width, &mlx->tmp.height);
	width = mlx->win_x / 2 - mlx->tmp.width / 2;
	height = mlx->win_y / 2 - mlx->tmp.height / 2 + mlx->win_y / 3;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tmp.img, width, height);
}

static void	draw_circle(t_mlx *mlx, int	angle)
{
	int	idx;
	int	jdx;
	int	tdx;
	int	radius;
	int	x;
	int	y;

	x = mlx->win_x / 2;
	y = mlx->win_y / 2;
	radius = mlx->win_y / 6;
	for (idx = 0; idx < angle; idx++)
	{
		for (jdx = 0; jdx < 4; jdx++)
		{
			for (tdx = 0; tdx < 4; tdx++)
			{
				put_pixel(mlx, x + radius * cos(get_radian(idx)) + jdx, y + radius * sin(get_radian(idx)) + tdx, 0xFFFFFF, &mlx->bg);
				put_pixel(mlx, x + radius * cos(get_radian(idx)) + jdx, y + radius * sin(get_radian(idx)) - tdx, 0xFFFFFF, &mlx->bg);
				put_pixel(mlx, x + radius * cos(get_radian(idx)) - jdx, y + radius * sin(get_radian(idx)) - tdx, 0xFFFFFF, &mlx->bg);
				put_pixel(mlx, x + radius * cos(get_radian(idx)) + jdx, y + radius * sin(get_radian(idx)) + tdx, 0xFFFFFF, &mlx->bg);
			}
		}
	}
}

static void	draw_loading(t_mlx *mlx)
{
	static int	angle;
	int width;
	int	height;

	width = mlx->win_x / 2 - mlx->logo.width / 2;
	height = mlx->win_y / 2 - mlx->logo.height / 2;
	if (mlx->phase == 2)
	{
		angle += 3;
		draw_circle(mlx, angle);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->title.img, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->logo.img, width, height);
		input_str(mlx, "now drawing", mlx->box[7][0] + mlx->win_x / 10, mlx->box[7][1] + mlx->win_y / 12);
	}
	if (angle == 360)
	{
		draw_circle(mlx, angle);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->title.img, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->logo.img, width, height);
		input_str(mlx, "press enter", mlx->box[7][0] + mlx->win_x / 10, mlx->box[7][1] + mlx->win_y / 12);
		angle = 0;
		mlx->phase = 3;
	}
}

static int	arr_num(char **arr)
{
	int	idx;

	for (idx = 0; arr[idx]; idx++)
		;
	return (idx);
}

static int	search_coprime(long num)
{
	int prime[27] = {2, 3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

	for (int idx = 0; idx < 27; idx++)
	{
		if (num % prime[idx] != 0)
			return (prime[idx]);
	}
	return (0);
}

static void	draw_res(t_mlx *mlx)
{
	int				res;
	int				coprime;
	struct timeval	mytime;
	int				width;

	gettimeofday(&mytime, 0);
	coprime = 0;
	coprime = search_coprime(mytime.tv_sec);
	res = (mytime.tv_sec) % (arr_num(mlx->name));
	mlx_destroy_image(mlx->mlx, mlx->title.img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	mlx->title.img = mlx_xpm_file_to_image(mlx->mlx, "./data/background/congrats.xpm", &mlx->title.width, &mlx->title.height);
	width = (mlx->win_x - mlx->title.width) / 2;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->title.img, width, 0);
	mlx_destroy_image(mlx->mlx, mlx->tmp.img);
	mlx->tmp.img = mlx_xpm_file_to_image(mlx->mlx, "./data/background/blackboard.xpm", &mlx->tmp.width, &mlx->tmp.height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tmp.img, (mlx->win_x - mlx->tmp.width) / 2, mlx->box[3][1]);
	input_str(mlx, mlx->name[res], (mlx->win_x - 70 * strlen(mlx->name[res])) / 2, mlx->box[4][1] + 80);
}

int		lodding_loop(t_mlx *mlx)
{
	if (mlx->phase == 2)
	{
		draw_loading(mlx);
		usleep(100);
	}
	return (0);
}

void	drawing(t_mlx *mlx)
{
	if (mlx->phase != 1)
		clear_image(mlx, 0xFFFFFFFF);
	if (!mlx->phase)
	{
		init_file(mlx);
		draw_title(mlx);
		mlx->phase = 1;
	}
	else if (mlx->phase == 1)
	{
	if (mlx->title.img)
		mlx_destroy_image(mlx->mlx, mlx->title.img);
		mlx->title.img = mlx_xpm_file_to_image(mlx->mlx, "./data/background/waiting_room.xpm", &mlx->title.width, &mlx->title.height);
		mlx->phase = 2;
	}
	else
	{
		clear_image(mlx, 0xFFFFFF);
		draw_res(mlx);
		mlx->phase = 0;
	}
}
