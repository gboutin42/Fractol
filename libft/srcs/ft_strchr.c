/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:51:32 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:41:45 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)s;
	if ((char)c == '\0' && str[i + 1] == '\0')
		return (str++);
	while (i < ft_strlen(s) + 1)
	{
		if ((char)c == str[0])
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
