/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:27:26 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:41:31 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *dest;

	if (!(dest = (size_t*)malloc(sizeof(size_t) * size)))
		return (NULL);
	ft_memset(dest, 0, size);
	return (dest);
}
