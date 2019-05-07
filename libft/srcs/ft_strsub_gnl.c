/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:17:58 by gboutin           #+#    #+#             */
/*   Updated: 2019/01/07 17:18:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strsub_gnl(char const *s, unsigned int start, size_t len)
{
	char	*section;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	section = ft_strnew(len + 1);
	while (len != 0)
	{
		section[i] = s[start + i];
		i++;
		len--;
	}
	section[i] = '\0';
	return (section);
}
