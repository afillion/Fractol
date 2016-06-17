#include "fractol.h"
#include <stdio.h>

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse = %d , %d : %d\n", x, y, button);
	draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key = %d\n", keycode);
	if (keycode == 82)
		e->julia = 0;
	if (keycode == 83)
		e->julia = 1;
	if (keycode == 84)
		e->julia = 2;
	if (keycode == 18)
		e->julia = 3;
	if (keycode == 19)
		e->julia = 4;
	if (keycode == 20)
		e->julia = 5;
	if (keycode == 21)
		e->julia = 6;
	if (keycode == 23)
		e->julia = 7;
	if (keycode == 53)
		exit(0);
	draw(e);
	return (0);
}

int		mouse_motion_hook(int x, int y, t_env *e)
{
	printf("mouse_motion = x : %d\t y : %d\n", x, y);
	if (x <= 800 && x >= 0)
		e->ptr_x = x;
	if (y <= 800 && y >= 0)
		e->ptr_y = y;
	draw(e);
	return (0);
}
