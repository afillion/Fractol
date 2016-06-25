#include "fractol.h"

void	init(t_env *e, t_frac *f)
{
	ask_reset(e);
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
	else if (e->draw == 3)
	{
		f->c_r = 0.285;
		f->c_i = 0.01;
	}
	else if (e->draw >= 5 && e->draw <= 10)
		define_frac(e, f);
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
