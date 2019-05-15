/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:13:18 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/09 14:00:57 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom_in(int x, int y, t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	X1 = (x / VARZOOM + X1) - (x / (VARZOOM * 1.1));
	Y1 = (y / VARZOOM + Y1) - (y / (VARZOOM * 1.1));
	VARZOOM *= 1.1;
	if (ITERATION_MAX + 1 <= 500)
		ITERATION_MAX += 1;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		zoom_out(int x, int y, t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	if ((VARZOOM / 1.1) >= 0.794793)
	{
		X1 = (x / VARZOOM + X1) - (x / (VARZOOM / 1.1));
		Y1 = (y / VARZOOM + Y1) - (y / (VARZOOM / 1.1));
		VARZOOM /= 1.1;
		if (ITERATION_MAX - 1 > 5)
			ITERATION_MAX -= 1;
	}
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		ft_iteration_more(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	if (ITERATION_MAX + 3 <= 500)
		ITERATION_MAX += 3;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		ft_iteration_minus(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	if (ITERATION_MAX - 3 >= 5)
		ITERATION_MAX -= 3;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}
