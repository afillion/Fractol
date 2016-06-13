#include "fractol.h"

void	draw(t_env e)
{
	t_mand	m;

	m.i = 0;
	m.x = 0;
	m.y = 0;
	m.x1 = -2.1;
	m.x2 = 0.6;
	m.y1 = -1.2;
	m.y2 = 1.2;
	m.zoom = 100;
	m.max = 50;
	m.image_x = (m.x2 - m.x1) * m.zoom;
	m.image_y = (m.y2 - m.y1) * m.zoom;
	e.img = mlx_new_image(e.mlx, (int)m.image_x, (int)m.image_y);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
	while (m.x < m.image_x)
	{
		m.y = 0;
		while (m.y < m.image_y)
		{
			m.c_r = m.x / m.zoom + m.x1;
			m.c_i = m.y / m.zoom + m.y1;
			m.z_r = 0;
			m.z_i = 0;
			m.i = 0;
			while (m.z_r * m.z_r + m.z_i * m.z_i < 4 && m.i < m.max)
			{
				m.tmp = m.z_r;
				m.z_r = m.z_r * m.z_r - m.z_i * m.z_i + m.c_r;
				m.z_i = 2 * m.z_i * m.tmp + m.c_i;
				m.i++;
			}
			if (m.i == m.max)
			{
				e.color = 0x000000;
				put_pixel_to_img(&e, m.x, m.y);
			}
			else
			{
				e.color = (m.i * 255) / m.max;
				put_pixel_to_img(&e, m.x, m.y);
			}
			m.y++;
		}
		m.x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
}

void	put_pixel_to_img(t_env *e, int x, int y)
{
	int	pos;

	pos = (x * e->bpp / 8) + (y * e->size_line);
	e->data[pos] = e->color % 256;
	e->data[pos + 1] = (e->color >> 8) % 256;
	e->data[pos + 2] = (e->color >> 16) % 256;
}

int		expose_hook(t_env *e)
{
	draw(*e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	draw(*e);
	return (0);
}

int		main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "fractol");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return(0);
}
