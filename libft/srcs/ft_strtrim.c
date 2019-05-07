/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:24:32 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:42:14 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	while (s[size - 1] == ' ' || s[size - 1] == '\t' || s[size - 1] == '\n')
		size--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		size--;
	if (size <= 0)
		size = 0;
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (str == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < size)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
