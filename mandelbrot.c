#include "fractol.h"

void	draw_mandelbrot(t_env *e)
{
	t_frac	f;

	init_julia(e, &f);
	if (e->zoom == 1)
		zoom(e, &f);
	while (f.x < f.image_x)
	{
		f.y = 0;
		while (f.y < f.image_y)
		{
			f.c_r = (f.x + f.x1) / f.zoom ;
			f.c_i = (f.y + f.y1) / f.zoom ;
			f.z_r = 0;
			f.z_i = 0;
			if (e->frac == 1)
			{
				f.z_r = get_complex(e->ptr_x);
				f.z_i = get_complex(e->ptr_y);
			}
			fill_img(e, &f);
			f.y++;
		}
		f.x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
