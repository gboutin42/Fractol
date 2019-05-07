/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:41:19 by mcoadou           #+#    #+#             */
/*   Updated: 2019/04/17 13:20:44 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long			ft_strtrol2(char *str, int base, int neg)
{
	int				c;
	int				i;
	long long		nbr;

	i = 0;
	nbr = 0;
	c = 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		base = 16;
		i += 2;
	}
	while ((c = str[i++]) && c != '\0' && c != ' ')
	{
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c))
			c -= ft_isupper(c) ? 'A' - 10 : 'a' - 10;
		nbr *= base;
		nbr += c;
	}
	return (nbr * neg);
}

long				ft_strtol(const char *nptr, int base)
{
	int				c;
	int				i;
	char			*str;
	int				neg;

	i = 0;
	neg = 1;
	c = 0;
	str = (char *)nptr;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		neg = 1;
		i++;
	}
	return (ft_strtrol2(str + i, base, neg));
}
