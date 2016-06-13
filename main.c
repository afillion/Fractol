#include "fractol.h"

void	draw(t_env e)
{
	int		x;
	int		y;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom;
	double	max;
	double	image_x;
	double	image_y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	double	tmp;

	i = 0;
	x = 0;
	y = 0;
	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 100;
	max = 50;
	image_x = (x2 - x1) * zoom;
	image_y = (y2 - y1) * zoom;
	e.img = mlx_new_image(e.mlx, (int)image_x, (int)image_y);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == max)
			{
				e.color = 0x000000;
				put_pixel_to_img(&e, x, y);
			}
			else
			{
				e.color = (i * 255) / max;
				put_pixel_to_img(&e, x, y);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
}

void	put_pixel_to_img(t_env *e, int x, int y)
{
	int	pos;

	pos = (x * e->bpp / 8) + (y * e->size_line);
	e->data[pos] = e->color % 256;
	e->data[pos + 1] = (e->color >> 8) % 256;
	e->data[pos + 2] = (e->color >> 16) % 256;
}

int		expose_hook(t_env *e)
{
	draw(*e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	draw(*e);
	return (0);
}

int		main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 240, 240, "fractol");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return(0);
}
