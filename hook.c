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
