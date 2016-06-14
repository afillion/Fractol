#include "fractol.h"

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
	draw_julia(*e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	draw_julia(*e);
	return (0);
}

void	ft_exit(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		e.filename = av[1];
	}
	else
		ft_exit("Usage: './fractol <name>' You can choose between ..");
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 700, 700, e.filename);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return(0);
}
