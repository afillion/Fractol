/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:19:00 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 17:01:01 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 5 || button == 4 || button == 1)
	{
		e->mx = x;
		e->my = y;
		if (button == 5 && e->nb_zm < 40)
		{
			e->nb_zm++;
			e->zm *= 1.5;
			e->button = button;
			e->zoom = 1;
		}
		else if (button == 4)
		{
			e->nb_zm--;
			e->zm /= 1.5;
			e->button = button;
			e->zoom = 1;
		}
		if (button == 1)
			e->move = 1;
		draw(e);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 256)
		e->frac = 100;
	else if (keycode == 81 || keycode == 75)
		what_draw(e, keycode);
	else if (keycode >= 123 && keycode <= 126)
		what_move(e, keycode);
	else if (keycode == 69)
		e->zm *= 1.5;
	else if (keycode == 78)
		e->zm /= 1.5;
	else if (keycode == 83)
		e->frac = 1;
	else if (keycode == 84)
		e->frac = 2;
	else if (keycode >= 18 && keycode <= 37)
		color(e, keycode);
	else if (keycode == 4)
		e->hide = 1;
	else if (keycode == 5)
		e->hide = 0;
	else if (keycode == 53)
		exit(0);
	draw(e);
	return (0);
}

int		mouse_motion_hook(int x, int y, t_env *e)
{
	if (x <= 800 && x >= 0)
		e->ptr_x = x;
	if (y <= 800 && y >= 0)
		e->ptr_y = y;
	if (e->frac == 1)
		draw(e);
	return (0);
}
