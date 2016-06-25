/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:18:51 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:22:45 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_env *e, t_frac *f)
{
	if (e->zoom == 1)
		zoom(e, f);
	if (e->move == 1)
		move(e, f);
	while (f->x < f->image_x)
	{
		f->y = 0;
		while (f->y < f->image_y)
		{
			motion(e, f);
			if (e->nb_zm >= 40)
				break ;
			fill_img(e, f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->hide == 0)
		put_overlay(e);
}

void	motion(t_env *e, t_frac *f)
{
	if (e->frac == 1)
	{
		f->c_r = get_complex(e->ptr_x);
		e->tmp_cr = f->c_r;
		f->c_i = get_complex(e->ptr_y);
		e->tmp_ci = f->c_i;
	}
	else if (e->frac == 2)
	{
		f->c_r = e->tmp_cr;
		f->c_i = e->tmp_ci;
	}
}
