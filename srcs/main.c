/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:19:14 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/07 11:28:35 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia")
	&& ft_strcmp(av[1], "burningship")) != 0)
	{
		ft_error("Usage: ./fractol\t[mandelbrot] [burningship] [julia]", 0);
		return (0);
	}
	if (!(data.title = (char*)malloc(sizeof(char) * ft_strlen(av[1]))))
		return (0);
	data.title = ft_strcpy(data.title, av[1]);
	smlx_init(&data);
	return (0);
}
