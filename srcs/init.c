/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:18:55 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/10 12:03:34 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		init_commands(t_data *data)
{
	mlx_mouse_hook(WINPTR, zoom_mouse, data);
	mlx_hook(WINPTR, 6, 1L << 6, mouse, data);
	mlx_hook(WINPTR, 2, 0, deal_key, data);
	mlx_hook(WINPTR, 17, 1L << 17, deal_mouse, data);
}

void			init_fractale(t_data *data, char *title)
{
	if (ft_strcmp(title, "mandelbrot") == 0)
		data->fractal = 1;
	else if (ft_strcmp(title, "burningship") == 0)
		data->fractal = 2;
	else if (ft_strcmp(title, "creation") == 0)
		data->fractal = 3;
	else if (ft_strcmp(title, "creation_2") == 0)
		data->fractal = 4;
	else if (ft_strcmp(title, "tricorn") == 0)
		data->fractal = 5;
	else if (ft_strcmp(title, "inverse_mandelbrot") == 0)
		data->fractal = 6;
	else if (ft_strcmp(title, "julia") == 0)
		data->fractal = 7;
	else if (ft_strcmp(title, "julia_2") == 0)
		data->fractal = 8;
}

void			select_fractal(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	if (data->fractal >= 1 && data->fractal <= 6)
		init_reset_variable(data);
	else if (data->fractal == 7)
		init_variable_julia(data);
	else if (data->fractal == 8)
		init_variable_julia_2(data);
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void			smlx_init(t_data *data)
{
	CR = 0;
	CI = 0;
	data->bpp = 32;
	data->size_ln = WIDTH * 4;
	data->endian = 0;
	if (!(MLXPTR = mlx_init()))
		ft_exit("Problem mlx_init");
	if (!(WINPTR = mlx_new_window(MLXPTR, WIDTH, WIDTH, "My Fractol ^^")))
		ft_exit("Problem mlx_new_window");
	if (!(IMGPTR = mlx_new_image(MLXPTR, WIDTH, WIDTH)))
		ft_exit("Problem mlx_new_image");
	if (!(IMGDATA = mlx_get_data_addr(IMGPTR, &data->bpp, &data->size_ln,
			&data->endian)))
		ft_exit("Problem mlx_get_data_addr");
	ft_color(data);
	select_fractal(data);
	init_commands(data);
	mlx_loop(MLXPTR);
}

void			init_array_fractal(void (*fractal[])(t_data *data))
{
	fractal[1] = ft_mandelbrot_pthread;
	fractal[2] = ft_burningship_pthread;
	fractal[3] = ft_creation_pthread;
	fractal[4] = ft_creation_pthread_2;
	fractal[5] = ft_tricorn_pthread;
	fractal[6] = ft_inverse_mandelbrot_pthread;
	fractal[7] = ft_julia_pthread;
	fractal[8] = ft_julia_pthread_2;
}
