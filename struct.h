#ifndef	STRUCT_H
# define STRUCT_H

# include "./minilibx/mlx.h"
# include "./include/mlx_key.h"
# include "./gnl/get_next_line.h"
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_img
{
	void	*img;
	void	*img_addr;
	int		width;
	int		height;
	int		bpp;
	int		size_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	struct s_img	bg;
	struct s_img	title;
	struct s_img	logo;
	struct s_img	alpha[27];
	struct s_img	tmp;
	int		win_x;
	int		win_y;
	int		map_y;
	char	**name;
	int		**box;
	int		phase;
}	t_mlx;

int		err_msg(char *str);
int		txt_to_arr(t_mlx *mlx, char *str);
int		mouse_hook(int keycode, t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
void	drawing(t_mlx *mlx);
int		display(t_mlx *mlx);
int		txt_to_arr(t_mlx *mlx, char	*str);
void	put_pixel(t_mlx *mlx, int x, int y, int color, t_img *img);
int		mlx_exit(t_mlx *mlx);
int		lodding_loop(t_mlx *mlx);

#endif
