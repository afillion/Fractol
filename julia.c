#include "fractol.h"

void	draw_julia(t_env e)
{
	t_jul	j;

	j.x = 0;
	j.x1 = -1;
	j.x2 = 1;
	j.y1 = -1.2;
	j.y2 = 1.2;
	j.zoom = 250;
	j.max = 150;
	j.image_x = (j.x2 - j.x1) * j.zoom;
	j.image_y = (j.y2 - j.y1) * j.zoom;
	e.img = mlx_new_image(e.mlx, (int)j.image_x, (int)j.image_y);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
	while (j.x < j.image_x)
	{
		j.y = 0;
		while (j.y < j.image_y)
		{
			j.c_r = 0.285;
			j.c_i = 0.01;
			j.z_r = j.x / j.zoom + j.x1;
			j.z_i = j.y / j.zoom + j.y1;
			j.i = 0;
			while (j.z_r * j.z_r + j.z_i * j.z_i < 4 && j.i < j.max)
			{
				j.tmp = j.z_r;
				j.z_r = j.z_r * j.z_r - j.z_i * j.z_i + j.c_r;
				j.z_i = 2 * j.z_i * j.tmp + j.c_i;
				j.i++;
			}
			if (j.i == j.max)
			{
				e.color = 0x000000;
				put_pixel_to_img(&e, j.x, j.y);
			}
			else
			{
				e.color = (j.i * 255) / j.max;
				put_pixel_to_img(&e, j.x, j.y);
			}
			j.y++;
		}
		j.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
}
