/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delgrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:17:21 by gboutin           #+#    #+#             */
/*   Updated: 2019/01/07 17:17:25 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_delgrid(int size, char ***grid)
{
	int i;

	i = -1;
	if (*grid == NULL)
		return ((void)0);
	while (++i < size)
	{
		ft_strclr((*grid)[i]);
		ft_strdel(&(*grid)[i]);
	}
	free(*grid);
	*grid = NULL;
}
