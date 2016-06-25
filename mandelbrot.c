/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:19:10 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:19:11 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	algo_mandelbrot(t_env *e, t_frac *f)
{
	while (f->x < f->image_x)
	{
		f->y = 0;
		while (f->y < f->image_y)
		{
			f->c_r = (f->x + f->x1) / f->zoom;
			f->c_i = (f->y + f->y1) / f->zoom;
			f->z_r = 0;
			f->z_i = 0;
			if (e->frac == 1)
			{
				f->z_r = get_complex(e->ptr_x);
				f->z_i = get_complex(e->ptr_y);
			}
			if (e->nb_zm >= 40)
				break ;
			fill_img(e, f);
			f->y++;
		}
		f->x++;
	}
}

void	draw_mandelbrot(t_env *e, t_frac *f)
{
	if (e->zoom == 1)
		zoom(e, f);
	if (e->move == 1)
		move(e, f);
	algo_mandelbrot(e, f);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->hide == 0)
		put_overlay(e);
}
