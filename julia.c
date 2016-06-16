#include "fractol.h"

void	draw_julia(t_env e)
{
	t_frac	f;

	f.x = 0;
	f.x1 = -1;
	f.x2 = 1;
	f.y1 = -1.2;
	f.y2 = 1.2;
	f.zoom = 250;
	f.max = 150;
	f.image_x = (f.x2 - f.x1) * f.zoom;
	f.image_y = (f.y2 - f.y1) * f.zoom;
	e.img = mlx_new_image(e.mlx, (int)f.image_x, (int)f.image_y);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
	while (f.x < f.image_x)
	{
		f.y = 0;
		while (f.y < f.image_y)
		{
			f.c_r = get_complex(e.ptr_x);
			f.c_i = get_complex(e.ptr_y);
			f.z_r = f.x / f.zoom + f.x1;
			f.z_i = f.y / f.zoom + f.y1;
			f.i = 0;
			while (f.z_r * f.z_r + f.z_i * f.z_i < 4 && f.i < f.max)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = 2 * f.z_i * f.tmp + f.c_i;
				f.i++;
			}
			if (f.i == f.max)
			{
				e.color = 0x000000;
				put_pixel_to_img(&e, f.x, f.y);
			}
			else
			{
				e.color = (f.i * 255) / f.max;
				put_pixel_to_img(&e, f.x, f.y);
			}
			f.y++;
		}
		f.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 200, 200);
}

double	get_complex(int x)
{
	double c;

	if (x < 400 || x > 400)
		c = (x - 400) * 0.0025;
	else
		c = 0;
	return (c);
}
