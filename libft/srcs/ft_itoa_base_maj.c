/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:38:54 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/25 11:39:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(long value, int base)
{
	int			size;

	size = 0;
	if (value < 0)
	{
		value *= -1;
		size++;
	}
	while (value > 0)
	{
		value /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base_maj(int value, int base)
{
	char		*str;
	int			size;
	char		*tab;
	int			flag;

	flag = 0;
	size = ft_size(value, base);
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && (base == 10 || base == 2))
		flag = 1;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}
