/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:00:09 by gboutin           #+#    #+#             */
/*   Updated: 2019/01/05 01:01:24 by sun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*section;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(section = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len != 0)
	{
		section[i] = s[start + i];
		i++;
		len--;
	}
	section[i] = '\0';
	return (section);
}
