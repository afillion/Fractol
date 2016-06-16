#include "fractol.h"
#include <math.h>

void	draw_ship(t_env e)
{
	t_frac	f;

	f.i = 0;
	f.x = 0;
	f.y = 0;
	f.x1 = -2.1;
	f.x2 = 0.6;
	f.y1 = -1.2;
	f.y2 = 1.2;
	f.zoom = 250;
	f.max = 250;
	f.image_x = (f.x2 - f.x1) * f.zoom;
	f.image_y = (f.y2 - f.y1) * f.zoom;
	e.img = mlx_new_image(e.mlx, (int)f.image_x, (int)f.image_y);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
	while (f.x < f.image_x)
	{
		f.y = 0;
		while (f.y < f.image_y)
		{
			f.c_r = f.x / f.zoom + f.x1;
			f.c_i = f.y / f.zoom + f.y1;
			f.z_r = 0;
			f.z_i = 0;
			f.i = 0;
			while (f.z_r * f.z_r + f.z_i * f.z_i < 4 && f.i < f.max)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = 2 * fabs(f.z_i) * fabs(f.tmp) + f.c_i;
				f.i++;
			}
			if (f.i == f.max)
			{
				e.color = 0x000000;
				put_pixel_to_img(&e, f.x, f.y);
			}
			else
			{
				e.color = (f.i * 16777216) / f.max;
				put_pixel_to_img(&e, f.x, f.y);
			}
			f.y++;
		}
		f.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
}
