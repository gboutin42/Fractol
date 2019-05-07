/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:34:50 by gboutin           #+#    #+#             */
/*   Updated: 2019/02/11 14:16:48 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(long long value, unsigned int base)
{
	int size;

	size = 1;
	while (value > base)
	{
		value /= base;
		size++;
	}
	return (size);
}

char				*ft_itoa_base(long long value, char *base)
{
	char	*str;
	int		size;
	int		baselength;

	baselength = ft_strlen(base);
	size = ft_size(value, baselength);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = base[value % baselength];
		size--;
		value /= baselength;
	}
	return (str);
}
