/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:08:08 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:42:10 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
			i++;
		i--;
		while (i > j)
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i--;
			j++;
		}
		return (str);
	}
	return (0);
}
