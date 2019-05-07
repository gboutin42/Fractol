/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:56:37 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/03 16:48:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		translate_up(t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	Y1 += 5 / VARZOOM;
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
}

void		translate_down(t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	Y1 -= 5 / VARZOOM;
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
}

void		translate_left(t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	X1 += 5 / VARZOOM;
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
}

void		translate_right(t_data *data)
{
	void	(*fractal[5])(t_data *data);

	init_array_fractal(&(*fractal));
	X1 -= 5 / VARZOOM;
	if (data->fractal >= 1 && data->fractal <= 4)
		(*fractal[data->fractal])(data);
}

void		ft_stop_fractale(t_data *data)
{
	if (data->fractal == 2)
	{
		if (data->stop == 0)
			data->stop = 1;
		else
			data->stop = 0;
	}
}
