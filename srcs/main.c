/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:19:14 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/10 12:12:04 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			init_reset_variable(t_data *data)
{
	data->stop = 1;
	ITERATION_MAX = 50;
	X1 = -2;
	Y1 = -2;
	VARZOOM = 200;
}

static void		ft_usage(void)
{
	ft_putendl("Usage: ./fractol [fractale] [set of color]\n");
	ft_putendl(" fractale : enter the name of fractale (mandelbrot, julia, \
julia_2, tricorn, burningship, inverse_mandelbrot, creation, creation_2)\n");
	ft_putendl(" color    : enter the number of set of color");
	ft_putendl("            -  0: Black / Green / Red / Blue / Cyan / Pink / \
Yellow");
	ft_putendl("            -  1: Purple / Brown / Pastel Green / Dark \
Blue / Yellow Cheese / Saumon / Grey");
	ft_putendl("            -  2: Purple_2 / Saumon_2 / Grass / Pastel \
Yellow / Orange / Pastel Pink / Past Blue");
	ft_putendl("            -  3: Dark Red / Dark Orange / Dark Green / \
Dark Purple / Blue Sky / Pink Lady / Red X Mas");
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac != 3 || !(ft_atoi(av[2]) >= 0 && ft_atoi(av[2]) <= 3)
	|| (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia")
	&& ft_strcmp(av[1], "creation") && ft_strcmp(av[1], "julia_2")
	&& ft_strcmp(av[1], "tricorn") && ft_strcmp(av[1], "burningship")
	&& ft_strcmp(av[1], "creation_2")
	&& ft_strcmp(av[1], "inverse_mandelbrot")) != 0)
	{
		ft_usage();
		return (0);
	}
	data.select_color = ft_atoi(av[2]);
	init_fractale(&data, av[1]);
	smlx_init(&data);
	return (0);
}
