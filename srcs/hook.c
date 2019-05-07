/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 08:48:37 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/07 14:25:26 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			deal_key(int key, t_data *data)
{
	void	(*array[127])(t_data *data);

	array[15] = select_fractal;
	array[49] = ft_stop_fractale;
	array[53] = ft_close;
	array[69] = ft_iteration_more;
	array[78] = ft_iteration_minus;
	array[123] = translate_left;
	array[124] = translate_right;
	array[125] = translate_down;
	array[126] = translate_up;
	if (key == 15 || key == 53 || key == 69 || key == 78 || key == 123
		|| key == 124 || key == 125 || key == 126 || key == 49)
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
