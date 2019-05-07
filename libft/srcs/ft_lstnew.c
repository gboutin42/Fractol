/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:07:20 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:41:30 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	if (!(newlink = (void*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(newlink->content = (void*)malloc(sizeof(t_list))))
			return (NULL);
		ft_memcpy(newlink->content, (void*)content, content_size);
		newlink->content_size = content_size;
	}
	else
	{
		newlink->content = NULL;
		newlink->content_size = 0;
	}
	newlink->next = NULL;
	return (newlink);
}
