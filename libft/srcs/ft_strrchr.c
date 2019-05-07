/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:38:13 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:42:09 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s) + 1;
	str = (char*)s;
	while (*str)
		str++;
	while (i >= 0)
	{
		if ((char)c == *str)
			return (str);
		str--;
		i--;
	}
	return (NULL);
}
