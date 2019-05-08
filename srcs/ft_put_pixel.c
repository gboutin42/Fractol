/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:47:13 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/08 08:35:28 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_put_pixel(t_data *data, int color)
{
	int		pixel;

	if (IMGDATA)
	{
		pixel = (Y * data->size_ln) + (X * 4);
		IMGDATA[pixel] = (char)color;
		IMGDATA[pixel + 1] = (char)((color) >> 8);
		IMGDATA[pixel + 2] = (char)((color) >> 16);
	}
}

static void		ft_color_2(t_data *data)
{
	COLOR[3][0] = RED_DARK;
	COLOR[3][1] = ORANGE_DARK;
	COLOR[3][2] = GREEN_DARK;
	COLOR[3][3] = PURPLE_DARK;
	COLOR[3][4] = BLUE_SKY;
	COLOR[3][5] = PINK_LADY;
	COLOR[3][6] = RED_X_MAS;
}

void			ft_color(t_data *data)
{
	COLOR[0][0] = BLACK;
	COLOR[0][1] = GREEN;
	COLOR[0][2] = RED;
	COLOR[0][3] = BLUE;
	COLOR[0][4] = CYAN;
	COLOR[0][5] = PINK;
	COLOR[0][6] = YELLOW;
	COLOR[1][0] = PURPLE;
	COLOR[1][1] = BROWN;
	COLOR[1][2] = GREEN_PAST;
	COLOR[1][3] = BLUE_DARK;
	COLOR[1][4] = YELLOW_CHEESE;
	COLOR[1][5] = SAUMON;
	COLOR[1][6] = GREY;
	COLOR[2][0] = PURPLE_2;
	COLOR[2][1] = SAUMON_2;
	COLOR[2][2] = GRASS;
	COLOR[2][3] = YELLOW_PAST;
	COLOR[2][4] = ORANGE;
	COLOR[2][5] = PINK_PAST;
	COLOR[2][6] = BLUE_PAST;
	ft_color_2(data);
}

void			ft_menu(t_data *data)
{
	char		*iteration;
	char		*cr;
	char		*ci;

	iteration = ft_itoa(ITERATION_MAX);
	cr = ft_itoa(CR);
	ci = ft_itoa(CI);
	mlx_string_put(MLXPTR, WINPTR, 10, 2, WHITE, "Julia Move On/Off: Space");
	mlx_string_put(MLXPTR, WINPTR, 10, 17, WHITE, "Zoom: Scroll Up or Down");
	mlx_string_put(MLXPTR, WINPTR, 10, 32, WHITE, "Iteration: Num+ or Num-");
	mlx_string_put(MLXPTR, WINPTR, 10, 47, WHITE, "Reset: R");
	mlx_string_put(MLXPTR, WINPTR, 615, 2, WHITE, "Change Fractale: F");
	mlx_string_put(MLXPTR, WINPTR, 615, 17, WHITE, "Change Color:    C");
	mlx_string_put(MLXPTR, WINPTR, 615, 32, WHITE, "Moving:    ^ V < >");
	mlx_string_put(MLXPTR, WINPTR, 10, 775, WHITE, "Close: ESC");
	mlx_string_put(MLXPTR, WINPTR, 450, 775, WHITE, "CI: ");
	mlx_string_put(MLXPTR, WINPTR, 490, 775, WHITE, ci);
	mlx_string_put(MLXPTR, WINPTR, 550, 775, WHITE, "CR: ");
	mlx_string_put(MLXPTR, WINPTR, 590, 775, WHITE, cr);
	mlx_string_put(MLXPTR, WINPTR, 650, 775, WHITE, "Iteration: ");
	mlx_string_put(MLXPTR, WINPTR, 760, 775, WHITE, iteration);
	free(iteration);
	free(cr);
	free(ci);
}
