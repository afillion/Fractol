#include "fractol.h"
#include <math.h>
#include <stdio.h>

void	choose_julia(t_env *e, t_frac *f)
{
	if (e->frac == 3)
	{
		f->c_r = -0.765;
		f->c_i = 0.1025;
	}
	if (e->frac == 4)
	{
		f->c_r = 0.3;
		f->c_i = 0.0225;
	}
	if (e->frac == 5)
	{
		f->c_r = -0.5525;
		f->c_i = -0.4775;
	}
	if (e->frac == 6)
	{
		f->c_r = 0.1675;
		f->c_i = 0.5825;
	}
	if (e->frac == 7)
	{
		f->c_r = -0.4225;
		f->c_i = -0.6675;
	}
}

void	draw_julia(t_env *e)
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
			if (e->frac == 1)
			{
				f.c_r = get_complex(e->ptr_x);
				e->tmp_cr = f.c_r;
				f.c_i = get_complex(e->ptr_y);
				e->tmp_ci = f.c_i;
			}
			else if (e->frac == 2)
			{
				f.c_r = e->tmp_cr;
				f.c_i = e->tmp_ci;
			}
			if (e->nb_zm >= 40)
				break ;
			f.z_r = (f.x + f.x1) / f.zoom;
			f.z_i = (f.y + f.y1) / f.zoom;
			fill_img(e, &f);
			f.y++;
		}
		f.x++;
	}
	printf("color : %d\n", e->k);
	printf("nb_zm : %d\n", e->nb_zm);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
