/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:18:40 by afillion          #+#    #+#             */
/*   Updated: 2016/06/25 17:02:03 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				x1;
	int				y1;
	double			iter;
	int				button;
	int				k;
	int				nb_zm;
	int				move;
	int				keycode;
	int				hide;
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

void				put_overlay(t_env *e);
void				algo_mandelbrot(t_env *e, t_frac *f);

void				what_draw(t_env *e, int keycode);
void				what_move(t_env *e, int keycode);
void				ask_reset(t_env *e);
void				define_frac(t_env *e, t_frac *f);
void				color(t_env *e, int keycode);
void				motion(t_env *e, t_frac *f);

void				init_env(t_env *e);

void				fill_ship(t_env *e, t_frac *f);

void				zoom(t_env *e, t_frac *f);

void				move(t_env *e, t_frac *f);

int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_motion_hook(int x, int y, t_env *e);

void				draw(t_env *e);
double				get_complex(int x);
void				put_pixel_to_img(t_env *e, int x, int y);

void				init(t_env *e, t_frac *f);

void				draw_mandelbrot(t_env *e, t_frac *f);

void				choose_julia(t_env *e, t_frac *f);
void				fill_img(t_env *e, t_frac *f);
void				draw_julia(t_env *e, t_frac *f);

void				draw_ship(t_env *e, t_frac *f);

void				draw_rabbit(t_env *e, t_frac *f);

void				ft_exit(char *s);
#endif
