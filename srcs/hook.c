/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:48:37 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/10 12:03:43 by gboutin          ###   ########.fr       */
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
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	if (S_COLOR < 3)
		S_COLOR++;
	else
		S_COLOR = 0;
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}

void		ft_choose_fractale(t_data *data)
{
	void	(*fractal[FRACTAL_NUMBER])(t_data *data);

	init_array_fractal(&(*fractal));
	init_reset_variable(data);
	((data->fractal < 8) ? data->fractal++ : (data->fractal = 1));
	if (data->fractal == 7)
	{
		CR = 0.0;
		CI = 110.0;
	}
	else if (data->fractal == 8)
	{
		CR = 130.0;
		CI = 504.0;
	}
	else
	{
		CR = 0;
		CI = 0;
	}
	if (data->fractal >= FRACTAL_NB_MIN && data->fractal <= FRACTAL_NB_MAX)
		(*fractal[data->fractal])(data);
}
