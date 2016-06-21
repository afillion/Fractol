#include "fractol.h"

void	init_julia(t_env *e, t_frac *f)
{
	if (e->julia == 100)
	{
		e->updown = 0;
		e->leftright = 0;
		e->zm = 0;
		e->julia = 0;
	}
	f->x = 0;
	f->x1 = -400 + e->leftright;
	f->y1 = -400 + e->updown;
	f->zoom = 300 + e->zm;
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
	if (e->julia != 100 && e->julia != 2 && e->julia != 0)
		choose_julia(e, f);
}

void	init_mandelbrot(t_env *e, t_frac *f)
{
	f->x = 0;
	f->x1 = -400;
	f->y1 = -400;
	f->zoom = 200;
	f->max = 100;
	f->image_x = 800;
	f->image_y = 800;
	e->tmp_cr = 0;
}
