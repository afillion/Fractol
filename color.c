/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:18:15 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 16:18:18 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(t_env *e, int keycode)
{
	if (keycode == 18)
		e->k = 1048576;
	else if (keycode == 19)
		e->k = 4096;
	else if (keycode == 20)
		e->k = 8;
	else if (keycode == 21)
		e->k = 192001;
	else if (keycode == 23)
		e->k = 266001;
	else if (keycode == 22)
		e->k = 16776685;
	else if (keycode == 26)
		e->k = 523001;
	else if (keycode == 28)
		e->k = 459001;
	else if (keycode == 25)
		e->k = 100000000;
	else if (keycode == 35 && (e->k + 1000) < 2147483647)
		e->k += 1000;
	else if (keycode == 37 && (e->k - 1000) > -2147483647)
		e->k -= 1000;
}
