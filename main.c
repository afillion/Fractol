/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:20:26 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 17:02:27 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *e)
{
	e->width = 800;
	e->height = 800;
	e->leftright = 0;
	e->updown = 0;
	e->zoom = 0;
	e->zm = 1;
	e->iter = 0.0;
	e->frac = 0;
	e->y1 = 0;
	e->k = 2560;
	e->hide = 0;
	e->nb_zm = 0;
	e->move = 0;
	e->x1 = 0;
	e->mx = 0;
	e->my = 0;
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, 800, 800);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	e->win = mlx_new_window(e->mlx, e->width, e->height, e->filename);
}

void	show_names(void)
{
	ft_putendl_fd("You can choose between :\n", 2);
	ft_putendl_fd("\t- Mandelbrot\n", 2);
	ft_putendl_fd("\t- Julia\n", 2);
	ft_putendl_fd("\t- Ship\n", 2);
	ft_putendl_fd("\t- Rabbit\n", 2);
	ft_putendl_fd("\t- Dragon\n", 2);
	ft_putendl_fd("\t- Galaxy\n", 2);
	ft_putendl_fd("\t- Thunder\n", 2);
}

void	ft_exit(char *s)
{
	ft_putendl_fd(s, 2);
	show_names();
	exit(0);
}

void	open_frac(t_env *e, char **av)
{
	e->filename = av[1];
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		e->draw = 1;
	else if (ft_strcmp(av[1], "Julia") == 0)
		e->draw = 3;
	else if (ft_strcmp(av[1], "Ship") == 0)
		e->draw = 2;
	else if (ft_strcmp(av[1], "Rabbit") == 0)
		e->draw = 4;
	else if (ft_strcmp(av[1], "Dragon") == 0)
		e->draw = 5;
	else if (ft_strcmp(av[1], "Thunder") == 0)
		e->draw = 6;
	else if (ft_strcmp(av[1], "Galaxy") == 0)
		e->draw = 9;
	else
		ft_exit("Wrong fractal's name !");
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		open_frac(&e, av);
	}
	else
		ft_exit("Usage: './fractol <name>'");
	init_env(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, 6, 1L << 6, mouse_motion_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
