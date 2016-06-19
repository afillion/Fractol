#include "fractol.h"

void	draw_rabbit(t_env *e)
{
	t_frac	f;

	init_mandelbrot(e, &f);
	while (f.x < f.image_x)
	{
		f.y = 0;
		while (f.y < f.image_y)
		{
			if (e->julia == 0)
			{
				f.c_r = -0.123;
				f.c_i = 0.745;
			}
			if (e->julia == 1)
			{
				f.c_r = get_complex(e->ptr_x);
				f.c_i = get_complex(e->ptr_y);
			}
			f.z_r = (f.x + f.x1) / f.zoom;
			f.z_i = (f.y + f.y1) / f.zoom;
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
				e->color = 0x000000;
				put_pixel_to_img(e, f.x, f.y);
			}
			else
			{
				e->color = (f.i * 255) / f.max;
				put_pixel_to_img(e, f.x, f.y);
			}
			f.y++;
		}
		f.x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
