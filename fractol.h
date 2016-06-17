#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/includes/get_next_line.h"

typedef struct		s_env
{
	void			*mlx;
	char			*filename;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	int				draw;
	double			width;
	double			height;
	int				ptr_x;
	int				ptr_y;
	int				julia;
	double			tmp_cr;
	double			tmp_ci;
}					t_env;

typedef	struct		s_fractals
{
	int				x;
	int				y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	double			max;
	double			image_x;
	double			image_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
}					t_frac;

int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_motion_hook(int x, int y, t_env *e);

void				draw(t_env *e);
void				draw_mandelbrot(t_env *e);
void				init_julia(t_env *e, t_frac *f);
void				choose_julia(t_env *e, t_frac *f);
void				color_julia(t_env *e, t_frac *f);
void				draw_julia(t_env *e);
void				draw_ship(t_env *e);
void				draw_rabbit(t_env *e);
void				put_pixel_to_img(t_env *e, int x, int y);

double				get_complex(int x);

void				ft_exit(char *s);
#endif
