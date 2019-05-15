/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:21:38 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/10 11:22:33 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		inverse_mandelbrot_calc(t_data *data)
{
	CR = X / VARZOOM + X1;
	CI = Y / VARZOOM + Y1;
	data->tmp = (1 * CR) / (CR * CR + CI * CI);
	CI = (-1 * CI) / (CR * CR + CI * CI);
	CR = data->tmp;
	ZR = 0;
	ZI = 0;
	ITERATION = -1;
	while (++ITERATION < ITERATION_MAX && (ZR * ZR + ZI * ZI) < 4)
	{
		data->tmp = ZR * ZR - ZI * ZI + CR;
		ZI = (2 * ZI * ZR) + CI;
		ZR = data->tmp;
	}
	if (ITERATION == ITERATION_MAX)
		ft_put_pixel(data, BLUE_DARK);
	else
		ft_put_pixel(data, COLOR[S_COLOR][ITERATION % 7]);
}

static void		*ft_inverse_mandelbrot(void *tab)
{
	int			i;
	t_data		*data;

	data = (t_data*)tab;
	X = -1;
	i = Y;
	while (++X < WIDTH)
	{
		Y = i;
		while (Y++ < data->var.y_max)
			inverse_mandelbrot_calc(data);
	}
	return (tab);
}

void			ft_inverse_mandelbrot_pthread(t_data *data)
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
		pthread_create(&t_phread[i], NULL, ft_inverse_mandelbrot, &tab[i]);
	}
	while (i--)
		pthread_join(t_phread[i], NULL);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	ft_menu(data);
}
