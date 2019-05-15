/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:56:37 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/10 11:32:39 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		moving_up(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	Y1 += 5 / VARZOOM;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		moving_down(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	Y1 -= 5 / VARZOOM;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		moving_left(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	X1 += 5 / VARZOOM;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		moving_right(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	X1 -= 5 / VARZOOM;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		ft_stop_fractale(t_data *data)
{
	if (data->fractal >= 7 && data->fractal <= 8)
	{
		if (data->stop == 0)
			data->stop = 1;
		else
			data->stop = 0;
	}
}
