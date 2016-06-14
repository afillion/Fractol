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
}					t_env;

typedef	struct		s_mandelbrot
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
}					t_mand;

typedef struct		s_julia
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
}					t_jul;

void				draw_mandelbrot(t_env e);
void				draw_julia(t_env e);
void				ft_exit(char *s);
void				put_pixel_to_img(t_env *e, int x, int y);

#endif
