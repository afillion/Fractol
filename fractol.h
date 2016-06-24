#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/includes/get_next_line.h"
# define SIZE 400

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
	int				frac;
	double			tmp_cr;
	double			tmp_ci;
	int				zoom;
	double			zm;
	int				updown;
	int				leftright;
	int				mx;
	int				my;
	double			tmp_x1;
	double			tmp_y1;
	int				mx2;
	int				my2;
	int				tmp_x;
	int				tmp_y;
	int				x1;
	int				y1;
	double			iter;
	int				button;
	int				k;
	int				nb_zm;
}					t_env;

typedef	struct		s_fractals
{
	int				x;
	int				y;
	double			x1;
	double			y1;
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

void				zoom(t_env *e, t_frac *f);

int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_motion_hook(int x, int y, t_env *e);

void				draw(t_env *e);
double				get_complex(int x);
void				put_pixel_to_img(t_env *e, int x, int y);

void				init_mandelbrot(t_env *e, t_frac *f);
void				init_julia(t_env *e, t_frac *f);

void				draw_mandelbrot(t_env *e);

void				choose_julia(t_env *e, t_frac *f);
void				fill_img(t_env *e, t_frac *f);
void				draw_julia(t_env *e);

void				draw_ship(t_env *e);

void				draw_rabbit(t_env *e);

void				ft_exit(char *s);
#endif
