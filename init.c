#include "fractol.h"

void	init_julia(t_env *e, t_frac *f)
{
	if (e->frac == 100)
	{
		e->updown = 0;
		e->leftright = 0;
		e->zm = 1;
		e->frac = 0;
		e->zoom = 0;
		e->x1 = 0;
		e->y1 = 0;
		e->iter = 0;
		e->nb_zm = 0;
	}
	f->x = 0;
	f->x1 = -400.0 + e->leftright;
	f->y1 = -400.0 + e->updown;
	f->zoom = 100.0 * e->zm;
	f->max = 150.0 + e->iter;
	f->image_x = 800;
	f->image_y = 800;
	if (e->draw == 4)
	{
		f->c_r = -0.123;
		f->c_i = 0.745;
	}
	if (e->draw == 2)
	{
		f->c_r = 0.285;
		f->c_i = 0.01;
	}
	if (e->frac == 0 && e->draw == 2)
	{
		f->c_r = 0.285;
		f->c_i = 0.01;
	}
	if (e->frac != 100 && e->frac != 2 && e->frac != 0)
		choose_julia(e, f);
}

//void	init_mandelbrot(t_env *e, t_frac *f)
//{
//	f->x = 0;
//	f->x1 = -400;
//	f->y1 = -400;
//	f->zoom = 200;
//	f->max = 100;
//	f->image_x = 800;
//	f->image_y = 800;
//	e->tmp_cr = 0;
//}
