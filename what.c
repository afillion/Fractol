/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:20:40 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:59:04 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	what_draw(t_env *e, int keycode)
{
	if ((keycode == 81 && e->draw != 9) || (keycode == 75 && e->draw != 1))
		e->frac = 100;
	if (keycode == 81 && e->draw != 9)
		e->draw += 1;
	else if (keycode == 75 && e->draw != 1)
		e->draw -= 1;
}

void	what_move(t_env *e, int keycode)
{
	if (keycode == 123)
		e->leftright += 25 * e->zm;
	else if (keycode == 124)
		e->leftright -= 25 * e->zm;
	else if (keycode == 125)
		e->updown -= 25 * e->zm;
	else if (keycode == 126)
		e->updown += 25 * e->zm;
	e->move = 0;
}

void	ask_reset(t_env *e)
{
	if (e->frac == 100)
	{
		e->updown = 0;
		e->leftright = 0;
		e->zm = 1;
		e->frac = 0;
		e->zoom = 0;
		e->x1 = 0;
		e->y1 = 0;
		e->iter = 0;
		e->nb_zm = 0;
		e->mx = 0;
		e->my = 0;
		e->move = 0;
	}
}

void	define_frac(t_env *e, t_frac *f)
{
	if (e->draw == 5)
	{
		f->c_r = -0.765;
		f->c_i = 0.1025;
	}
	if (e->draw == 6)
	{
		f->c_r = 0.3;
		f->c_i = 0.0225;
	}
	if (e->draw == 7)
	{
		f->c_r = 0.2525;
		f->c_i = 0;
	}
	if (e->draw == 8)
	{
		f->c_r = -0.4725;
		f->c_i = -0.5675;
	}
	if (e->draw == 9)
	{
		f->c_r = -0.4225;
		f->c_i = -0.6675;
	}
}
