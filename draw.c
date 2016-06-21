#include "fractol.h"

void	put_pixel_to_img(t_env *e, int x, int y)
{
	int	pos;

	pos = (x * e->bpp / 8) + (y * e->size_line);
	e->data[pos] = e->color % 256;
	e->data[pos + 1] = (e->color >> 8) % 256;
	e->data[pos + 2] = (e->color >> 16) % 256;
}

void	draw(t_env *e)
{
	if (e->draw == 1)
		draw_mandelbrot(e);
	else if (e->draw == 2)
		draw_julia(e);
	else if (e->draw == 3)
		draw_ship(e);
	else if (e->draw == 4)
		draw_rabbit(e);
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
