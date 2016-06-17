#include "fractol.h"

void	init_julia(t_env *e, t_frac *f)
{
	f->x = 0;
	f->x1 = -400;
	f->y1 = -400;
	f->zoom = 300;
	f->max = 50;
	f->image_x = 800;
	f->image_y = 800;
	e->img = mlx_new_image(e->mlx, (int)f->image_x, (int)f->image_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	if (e->julia == 0)
	{
		f->c_r = 0.285;
		f->c_i = 0.01;
	}
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
		e->color = f->i * (98410);
		put_pixel_to_img(e, f->x, f->y);
	}
}

void	draw_julia(t_env e)
{
	t_frac	f;

	init_julia(&e, &f);
	while (f.x < f.image_x)
	{
		f.y = 0;
		while (f.y < f.image_y)
		{
			if (e.julia == 1)
			{
				f.c_r = get_complex(e.ptr_x);
				f.c_i = get_complex(e.ptr_y);
			}
			f.z_r = (f.x + f.x1) / f.zoom ;
			f.z_i = (f.y + f.y1) / f.zoom ;
			f.i = 0;
			color_julia(&e, &f);
			f.y++;
		}
		f.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
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
