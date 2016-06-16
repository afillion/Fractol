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
			ft_exit("Wrong fractal's name ! Try Mandelbrot or Julia");
	}
	else
		ft_exit("Usage: './fractol <name>' You can choose between Mandelbrot or Julia");
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 700, 700, e.filename);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return(0);
}
