/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:19:47 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:19:54 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_env *e, int x, int y)
{
	int	pos;

	pos = (x * e->bpp / 8) + (y * e->size_line);
	e->data[pos] = e->color % 256;
	e->data[pos + 1] = (e->color >> 8) % 256;
	e->data[pos + 2] = (e->color >> 16) % 256;
}

void	draw(t_env *e)
{
	t_frac	f;

	init(e, &f);
	if (e->draw == 1)
		draw_mandelbrot(e, &f);
	else if (e->draw == 2)
		draw_ship(e, &f);
	else if (e->draw >= 3 && e->draw <= 9)
		draw_julia(e, &f);
}

void	fill_img(t_env *e, t_frac *f)
{
	f->i = 0;
	if (e->draw != 1)
	{
		f->z_r = (f->x + f->x1) / f->zoom;
		f->z_i = (f->y + f->y1) / f->zoom;
	}
	while (f->z_r * f->z_r + f->z_i * f->z_i < 4.0 && f->i < f->max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2.0 * f->z_i * f->tmp + f->c_i;
		f->i += 1.0;
	}
	if (f->i == f->max && e->draw != 2)
	{
		e->color = 0x000000;
		put_pixel_to_img(e, f->x, f->y);
	}
	else
	{
		e->color = ((int)f->i * (e->k));
		put_pixel_to_img(e, f->x, f->y);
	}
}

void	zoom(t_env *e, t_frac *f)
{
	if (e->button == 5)
	{
		f->x1 -= (SIZE + e->x1 * 1.5 - e->mx);
		e->x1 = (SIZE + e->x1 * 1.5 - e->mx);
		f->y1 -= (SIZE + e->y1 * 1.5 - e->my);
		e->y1 = (SIZE + e->y1 * 1.5 - e->my);
	}
	else if (e->button == 4)
	{
		f->x1 -= (SIZE + e->x1 / 1.5 - e->mx);
		e->x1 = (SIZE + e->x1 / 1.5 - e->mx);
		f->y1 -= (SIZE + e->y1 / 1.5 - e->my);
		e->y1 = (SIZE + e->y1 / 1.5 - e->my);
	}
	e->zoom = 0;
	e->iter += 50;
}

double	get_complex(int x)
{
	double c;

	if (x <= 800 || x > 0)
		c = (x - 400) * 0.0025;
	else if (x < 0)
		c = -1;
	else
		c = 1;
	return (c);
}
