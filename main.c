#include "fractol.h"

void	draw(t_env e)
{
	int x;
	int y;
	double x1;
	double x2;
	double y1;
	double y2;
	double zoom;
	double max;
	double image_x;
	double image_y;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double i;
	double tmp;

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
				mlx_pixel_put(e.mlx, e.win, x, y, 0x000000);
			}
			else
				mlx_pixel_put(e.mlx, e.win, x, y, (i*255) / max);
			y++;
		}
		x++;
	}
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
