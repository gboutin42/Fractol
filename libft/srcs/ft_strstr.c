/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:41:57 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:42:11 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*str1;
	const char	*str2;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		str1 = haystack;
		str2 = needle;
		while (*str2 && *haystack == *str2)
		{
			haystack++;
			str2++;
		}
		if (!*str2)
			return ((char*)str1);
		haystack = str1 + 1;
	}
	return (NULL);
}
