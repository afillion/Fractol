#include "fractol.h"
#include <stdio.h>

void	move(t_env *e, t_frac *f)
{
	if (e->move == 1)
	{
		f->x1 -= (SIZE + e->x1 - e->mx);
		e->x1 = (SIZE + e->x1 - e->mx);
		f->y1 -= (SIZE + e->y1 - e->my);
		e->y1 = (SIZE + e->y1 - e->my);
		e->move = 0;
	}
}
