/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:02:35 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:42:08 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dest;

	if (!(dest = (char*)malloc(sizeof(char) * (size) + 1)))
		return (NULL);
	dest = ft_memset(dest, (int)'\0', size + 1);
	return (dest);
}
