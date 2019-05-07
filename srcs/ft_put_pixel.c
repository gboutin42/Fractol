/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:47:13 by gboutin           #+#    #+#             */
/*   Updated: 2019/05/07 14:25:36 by gboutin          ###   ########.fr       */
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
	COLOR[24] = PURPLE_DARK;
	COLOR[25] = BLUE_SKY;
	COLOR[26] = PINK_LADY;
	COLOR[27] = RED_X_MAS;
}

void			ft_color(t_data *data)
{
	COLOR[0] = BLACK;
	COLOR[1] = GREEN;
	COLOR[2] = RED;
	COLOR[3] = BLUE;
	COLOR[4] = CYAN;
	COLOR[5] = PINK;
	COLOR[6] = YELLOW;
	COLOR[7] = PURPLE;
	COLOR[8] = GREEN_PAST;
	COLOR[9] = BROWN;
	COLOR[10] = BLUE_DARK;
	COLOR[11] = YELLOW_CHEESE;
	COLOR[12] = SAUMON;
	COLOR[13] = GREY;
	COLOR[14] = PURPLE_2;
	COLOR[10] = ORANGE;
	COLOR[16] = GRASS;
	COLOR[17] = PINK_PAST;
	COLOR[18] = SAUMON_2;
	COLOR[19] = YELLOW_PAST;
	COLOR[20] = BLUE_PAST;
	COLOR[21] = RED_DARK;
	COLOR[22] = ORANGE_DARK;
	COLOR[23] = GREEN_DARK;
	ft_color_2(data);
}

void			ft_menu(t_data *data)
{
	char		*iteration;

	iteration = ft_itoa(ITERATION_MAX);
	mlx_string_put(MLXPTR, WINPTR, 10, 2, WHITE, "Iteration: Num+ or Num-");
	mlx_string_put(MLXPTR, WINPTR, 10, 17, WHITE, "Zoom: Scroll Up or Down");
	mlx_string_put(MLXPTR, WINPTR, 10, 32, WHITE, "Julia Move On/Off: Space");
	mlx_string_put(MLXPTR, WINPTR, 10, 47, WHITE, "Reset: R");
	mlx_string_put(MLXPTR, WINPTR, 910, 2, WHITE, "UP:    ^");
	mlx_string_put(MLXPTR, WINPTR, 910, 17, WHITE, "Down:  V");
	mlx_string_put(MLXPTR, WINPTR, 910, 32, WHITE, "Left:  <");
	mlx_string_put(MLXPTR, WINPTR, 910, 47, WHITE, "Right: >");
	mlx_string_put(MLXPTR, WINPTR, 10, 975, WHITE, "Close: ESC");
	mlx_string_put(MLXPTR, WINPTR, 850, 975, WHITE, "Iteration: ");
	mlx_string_put(MLXPTR, WINPTR, 960, 975, WHITE, iteration);
	free(iteration);
}
