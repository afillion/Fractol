/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:19:35 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:19:36 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_overlay(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20,
			0xFF0000, "Commands : ");
	mlx_string_put(e->mlx, e->win, 20, 40,
			0xFF0000, "Move = Up Down Left Right");
	mlx_string_put(e->mlx, e->win, 20, 60, 0xFF0000, "Zoom + - (Pav.Num)");
	mlx_string_put(e->mlx, e->win, 20, 80,
			0xFF0000, "Zoom with mouse wheel on a point");
	mlx_string_put(e->mlx, e->win, 20, 100, 0xFF0000, "P and L change color");
	mlx_string_put(e->mlx, e->win, 20, 120,
			0xFF0000, "1 (Pav.Num) active motion");
	mlx_string_put(e->mlx, e->win, 20, 140, 0xFF0000,
			"2 (Pav.Num) stop motion and save");
	mlx_string_put(e->mlx, e->win, 20, 160, 0xFF0000, "1 to 9 set color");
	mlx_string_put(e->mlx, e->win, 20, 180, 0xFF0000,
			"Left clic move point to center");
	mlx_string_put(e->mlx, e->win, 20, 200, 0xFF0000, "CTRL reset variables");
	mlx_string_put(e->mlx, e->win, 20, 220, 0xFF0000,
			"= and / (Pav.Num) switch fractals");
	mlx_string_put(e->mlx, e->win, 20, 240,
			0xFF0000, "press h to hide this overlay");
	mlx_string_put(e->mlx, e->win, 20, 260,
			0xFF0000, "press g to display it again");
}
