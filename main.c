#include <stdio.h>
#include "fractol.h"

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
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			e.draw = 1;
		else if (ft_strcmp(av[1], "Julia") == 0)
			e.draw = 2;
		else if (ft_strcmp(av[1], "Ship") == 0)
			e.draw = 3;
		else if (ft_strcmp(av[1], "Rabbit") == 0)
			e.draw = 4;
		else
			ft_exit("Wrong fractal's name ! Try Mandelbrot, Julia, Ship or Rabbit");
	}
	else
		ft_exit("Usage: './fractol <name>' You can choose between Mandelbrot, Julia, Ship or Rabbit");
	e.width = 800;
	e.height = 800;
	e.leftright = 0;
	e.updown = 0;
	e.tmp_x = 0;
	e.tmp_y = 0;
	e.zoom = 0;
	e.zm = 1;
	e.iter = 0.0;
	e.frac = 0;
	e.y1 = 0;
	e.k = 1;
	e.nb_zm = 0;
	e.x1 = 0;
	e.mx = 0;
	e.my = 0;
	e.mlx = mlx_init();
	e.img = mlx_new_image(e.mlx, 800, 800);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
	e.win = mlx_new_window(e.mlx, e.width, e.height, e.filename);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, 6, 1L<<6, mouse_motion_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return(0);
}
