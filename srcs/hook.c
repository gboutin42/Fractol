/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:48:37 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/08 16:15:19 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			deal_key(int key, t_data *data)
{
	void	(*array[127])(t_data *data);

	array[3] = ft_choose_fractale;
	array[8] = ft_change_color;
	array[15] = select_fractal;
	array[49] = ft_stop_fractale;
	array[53] = ft_close;
	array[69] = ft_iteration_more;
	array[78] = ft_iteration_minus;
	array[123] = moving_left;
	array[124] = moving_right;
	array[125] = moving_down;
	array[126] = moving_up;
	if (key == 3 || key == 8 || key == 15 || key == 53 || key == 69
		|| key == 78 || key == 123 || key == 124 || key == 125 || key == 126
		|| key == 49)
		(*array[key])(data);
	return (key);
}

void		ft_close(t_data *data)
{
	free(data->title);
	mlx_destroy_image(MLXPTR, IMGPTR);
	mlx_destroy_window(MLXPTR, WINPTR);
	exit(0);
}

void		ft_change_color(t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	if (S_COLOR < 3)
		S_COLOR++;
	else
		S_COLOR = 0;
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
}

void		ft_choose_fractale(t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	if (data->fractal < 4)
		data->fractal++;
	else
		data->fractal = 1;
	if (data->fractal == 3)
	{
		CR = 0.0;
		CI = 110.0;
	}
	else if (data->fractal == 4)
	{
		CR = 130.0;
		CI = 504.0;
	}
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
}
