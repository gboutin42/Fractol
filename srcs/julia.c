/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 09:50:28 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/07 11:34:08 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			init_variable_julia(t_data *data)
{
	data->fractal = 2;
	ITERATION_MAX = 50;
	X1 = -1;
	Y1 = -1.2;
	VARZOOM = 200;
	CR = 0.285;
	CI = 0.01;
}

static void		julia_calc(t_data *data)
{
	ZR = X / VARZOOM + X1;
	ZI = Y / VARZOOM + Y1;
	ITERATION = -1;
	while (++ITERATION < ITERATION_MAX && (ZR * ZR + ZI * ZI) < 4)
	{
		data->tmp = ZR;
		ZR = ZR * ZR - ZI * ZI - 0.8 + (CR / WIDTH);
		ZI = (2 * ZI * data->tmp) + CI / WIDTH;
	}
	if (ITERATION == ITERATION_MAX)
		ft_put_pixel(data, BLUE_DARK);
	else
		ft_put_pixel(data, COLOR[ITERATION % 28]);
}

static void		*ft_julia(void *tab)
{
	int			i;
	t_data		*data;

	data = (t_data *)tab;
	X = -1;
	i = Y;
	while (++X < WIDTH)
	{
		Y = i;
		while (Y++ < data->var.y_max)
			julia_calc(data);
	}
	return (tab);
}

void			ft_julia_pthread(t_data *data)
{
	t_data		tab[THREAD_NUMBER];
	pthread_t	t_phread[THREAD_NUMBER];
	int			i;

	i = -1;
	while (++i < THREAD_NUMBER - 1)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_data));
		tab[i].var.y = THREAD_WIDTH * i;
		tab[i].var.y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t_phread[i], NULL, ft_julia, &tab[i]);
	}
	while (i--)
		pthread_join(t_phread[i], NULL);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	ft_menu(data);
}
