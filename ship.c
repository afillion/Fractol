/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:20:11 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:20:13 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	fill_ship(t_env *e, t_frac *f)
{
	f->c_r = (f->x + f->x1) / f->zoom;
	f->c_i = (f->y + f->y1) / f->zoom;
	f->z_r = 0;
	f->z_i = 0;
	f->i = 0;
	while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && f->i < f->max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * fabs(f->z_i) * fabs(f->tmp) + f->c_i;
		f->i++;
	}
	if (f->i == f->max)
	{
		e->color = 0x000000;
		put_pixel_to_img(e, f->x, f->y);
	}
	else
	{
		e->color = ((int)f->i * e->k);
		put_pixel_to_img(e, f->x, f->y);
	}
}

void	draw_ship(t_env *e, t_frac *f)
{
	if (e->zoom == 1)
		zoom(e, f);
	while (f->x < f->image_x)
	{
		f->y = 0;
		while (f->y < f->image_y)
		{
			if (e->nb_zm >= 40)
				break ;
			fill_ship(e, f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->hide == 0)
		put_overlay(e);
}
