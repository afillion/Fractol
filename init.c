/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:18:27 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:18:30 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_env *e, t_frac *f)
{
	ask_reset(e);
	f->x = 0;
	f->x1 = -400.0 + e->leftright;
	f->y1 = -400.0 + e->updown;
	f->zoom = 100.0 * e->zm;
	f->max = 150.0 + e->iter;
	f->image_x = 800;
	f->image_y = 800;
	if (e->draw == 4)
	{
		f->c_r = -0.123;
		f->c_i = 0.745;
	}
	else if (e->draw == 3)
	{
		f->c_r = 0.285;
		f->c_i = 0.01;
	}
	else if (e->draw >= 5 && e->draw <= 10)
		define_frac(e, f);
}
