/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:17:42 by gboutin           #+#    #+#             */
/*   Updated: 2019/01/07 17:17:45 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstrev(t_list **begin)
{
	t_list		*prev;
	t_list		*cur;
	t_list		*next;

	prev = NULL;
	next = NULL;
	cur = *begin;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*begin = prev;
	return (*begin);
}
