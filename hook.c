#include "fractol.h"
#include <stdio.h>

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("button = %d (%d;%d)\n", button, x, y);
	if (button == 1) //1 left clic, 5 wheel up
	{
		e->mx = x;
		e->mx2 = x;
		e->my = y;
		e->my2 = y;
		e->zoom = 1;
		draw(e);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key = %d\n", keycode);
	if (keycode == 256)
		e->julia = 100;
	else if (keycode == 123) //left
		e->leftright += 25;
	else if (keycode == 124) //right
		e->leftright -= 25;
	else if (keycode == 125) //down
		e->updown -= 25;
	else if (keycode == 126) //up
		e->updown += 25;
	else if (keycode == 69)
		e->zm += 25;
	else if (keycode == 78)
		e->zm -= 25;
	else if (keycode == 82)
		e->julia = 0;
	else if (keycode == 83)
		e->julia = 1;
	else if (keycode == 84)
		e->julia = 2;
	else if (keycode == 18)
		e->julia = 3;
	else if (keycode == 19)
		e->julia = 4;
	else if (keycode == 20)
		e->julia = 5;
	else if (keycode == 21)
		e->julia = 6;
	else if (keycode == 23)
		e->julia = 7;
	else if (keycode == 53)
		exit(0);
	draw(e);
	return (0);
}

int		mouse_motion_hook(int x, int y, t_env *e)
{
	printf("mouse : (%d;%d)\n", x, y);
	if (x <= 800 && x >= 0)
		e->ptr_x = x;
	if (y <= 800 && y >= 0)
		e->ptr_y = y;
	if (e->julia == 1)
		draw(e);
	return (0);
}
