/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:07:45 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/06 11:12:49 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			deal_mouse(t_data *data)
{
	free(data->title);
	mlx_destroy_image(MLXPTR, IMGPTR);
	mlx_destroy_window(MLXPTR, WINPTR);
	exit(0);
	return (0);
}

int			zoom_mouse(int mousecode, int x, int y, t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	if (x < 0 || x >= WIDTH || y < 0 || y >= WIDTH)
		return (0);
	if (mousecode == 4)
		zoom_in(x, y, data);
	if (mousecode == 5)
		zoom_out(x, y, data);
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
	return (0);
}

int			mouse(int x, int y, t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	if (x < 0 || x >= WIDTH || y < 0 || y >= WIDTH || data->stop == 1)
		return (0);
	CR = x * 2;
	CI = y * 2 - 800;
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
	return (0);
}
