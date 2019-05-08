/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:10:33 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/08 16:15:49 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>

/*
** -------------------------SIZE------------------------------
*/
# define WIDTH			800
# define THREAD_WIDTH	5
# define THREAD_NUMBER	160

/*
** -----------------------POINTER MLX-------------------------
*/
# define MLXPTR		data->mlx.mlx_ptr
# define WINPTR		data->mlx.win_ptr
# define IMGPTR		data->mlx.img_ptr
# define IMGDATA	data->mlx.img_data_ptr

/*
** --------------------VARIABLES DEFINE-----------------------
*/
# define ZR				data->var.z_r
# define ZI				data->var.z_i
# define CR				data->var.c_r
# define CI				data->var.c_i
# define X				data->var.x
# define X1				data->var.x1
# define Y				data->var.y
# define Y1				data->var.y1
# define VARZOOM		data->var.zoom
# define ITERATION		data->var.iteration
# define ITERATION_MAX	data->var.iteration_max

/*
** -------------------------COLOR-----------------------------
*/
# define COLOR			data->color
# define S_COLOR		data->select_color
# define CYAN			0x26e7f6
# define BLACK			0x000000
# define WHITE			0xffffff
# define YELLOW			0xe0fb07
# define GREEN			0x42f626
# define RED			0xdf3840
# define PINK			0xf670e3
# define BLUE			0x0860d0
# define PURPLE			0xa670ec
# define BROWN			0xbf7c17
# define BLUE_SKY		0x32d6e3
# define SAUMON			0xf0bf74
# define GREY			0xc0c0c0
# define PURPLE_2		0x660066
# define GRASS			0x008000
# define ORANGE			0xffa500
# define PINK_PAST		0xffd7d7
# define SAUMON_2		0xffe9d6
# define YELLOW_PAST	0xffffba
# define GREEN_PAST		0xbaffc9
# define BLUE_PAST		0xd0fff8
# define RED_DARK		0x5a0000
# define ORANGE_DARK	0x7d5d14
# define GREEN_DARK		0x034500
# define BLUE_DARK		0x001049
# define PURPLE_DARK	0x3f0363
# define PINK_LADY		0xde00ff
# define RED_X_MAS		0xff0000
# define YELLOW_CHEESE	0Xffe000

/*
** ------------------STRUCTURE POINTER MLX--------------------
*/
typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data_ptr;
}					t_env;

/*
** -----------STRUCTURE OF VARIABLE FOR FRACTAL---------------
*/
typedef struct		s_variable
{
	long double		x;
	long double		y;
	long double		y_max;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		x1;
	long double		y1;
	long double		zoom;
	int				iteration;
	int				iteration_max;
}					t_variable;

/*
** ----------------------STRUCTURE MAIN-----------------------
*/
typedef struct		s_data
{
	char			*title;
	int				size_ln;
	int				bpp;
	int				endian;
	int				stop;
	int				fractal;
	int				select_color;
	int				color[4][7];
	long double		tmp;
	t_variable		var;
	t_env			mlx;
}					t_data;

/*
** -------------------HOOK & MOUSE CONTROL--------------------
*/
int					deal_mouse(t_data *data);
int					deal_key(int key, t_data *data);
int					zoom_mouse(int mousecode, int x, int y, t_data *data);
int					mouse(int x, int y, t_data *data);
void				ft_close(t_data *data);
void				moving_up(t_data *data);
void				moving_down(t_data *data);
void				moving_left(t_data *data);
void				moving_right(t_data *data);
void				ft_stop_fractale(t_data *data);
void				zoom_in(int x, int y, t_data *data);
void				zoom_out(int x, int y, t_data *data);
void				ft_iteration_more(t_data *data);
void				ft_iteration_minus(t_data *data);

/*
** --------------------INIT COMANDS AND MLX-------------------
*/
void				smlx_init(t_data *data);
void				init_fractale(t_data *data, char *title);
void				init_array_fractal(void (*fractal[])(t_data *data));
void				init_variable_mandelbrot(t_data *data);
void				init_variable_julia(t_data *data);
void				init_variable_julia_2(t_data *data);
void				init_variable_burningship(t_data *data);
void				select_fractal(t_data *data);

/*
** --------------------------DISPLAY--------------------------
*/
void				ft_put_pixel(t_data *data, int color);
void				ft_color(t_data *data);
void				ft_menu(t_data *data);
void				ft_change_color(t_data *data);

/*
** -------------------------FRACTALS--------------------------
*/
void				ft_choose_fractale(t_data *data);
void				ft_mandelbrot_pthread(t_data *data);
void				ft_burningship_pthread(t_data *data);
void				ft_julia_pthread(t_data *data);
void				ft_julia_pthread_2(t_data *data);

#endif
