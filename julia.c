#include "fractol.h"

void	choose_julia(t_env *e, t_frac *f)
{
	if (e->julia == 3)
	{
		f->c_r = -0.765;
		f->c_i = 0.1025;
	}
	if (e->julia == 4)
	{
		f->c_r = 0.3;
		f->c_i = 0.0225;
	}
	if (e->julia == 5)
	{
		f->c_r = -0.5525;
		f->c_i = -0.4775;
	}
	if (e->julia == 6)
	{
		f->c_r = 0.1675;
		f->c_i = 0.5825;
	}
	if (e->julia == 7)
	{
		f->c_r = -0.4225;
		f->c_i = -0.6675;
	}
}

void	init_julia(t_env *e, t_frac *f)
{
	f->x = 0;
	f->x1 = -400;
	f->y1 = -400;
	f->zoom = 300;
	f->max = 100;
	f->image_x = 800;
	f->image_y = 800;
	f->c_r = 0.285;
	f->c_i = 0.01;
	if (e->julia == 0)
	{
		f->c_r = 0.285;
		f->c_i = 0.01;
	}
	if (e->julia != 1 && e->julia != 2 && e->julia != 0)
		choose_julia(e, f);
}

void	color_julia(t_env *e, t_frac *f)
{
	while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && f->i < f->max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * f->tmp + f->c_i;
		f->i++;
	}
	if (f->i == f->max)
	{
		e->color = 0x000000;
		put_pixel_to_img(e, f->x, f->y);
	}
	else
	{
		e->color = f->i * (16776685);
		put_pixel_to_img(e, f->x, f->y);
	}
}

void	draw_julia(t_env *e)
{
	t_frac	f;

	init_julia(e, &f);
	while (f.x < f.image_x)
	{
		f.y = 0;
		while (f.y < f.image_y)
		{
			if (e->julia == 1)
			{
				f.c_r = get_complex(e->ptr_x);
				e->tmp_cr = f.c_r;
				f.c_i = get_complex(e->ptr_y);
				e->tmp_ci = f.c_i;
			}
			if (e->julia == 2)
			{
				f.c_r = e->tmp_cr;
				f.c_i = e->tmp_ci;
			}
			f.z_r = (f.x + f.x1) / f.zoom;
			f.z_i = (f.y + f.y1) / f.zoom;
			f.i = 0;
			color_julia(e, &f);
			f.y++;
		}
		f.x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

double	get_complex(int x)
{
	double c;

	if (x <= 800 || x > 0)
		c = (x - 400) * 0.0025;
	else if (x < 0)
		c = -1;
	else
		c = 1;
	return (c);
}
