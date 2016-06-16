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
