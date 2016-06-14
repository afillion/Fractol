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
		draw_mandelbrot(*e);
	if (e->draw == 2)
		draw_julia(*e);
}
