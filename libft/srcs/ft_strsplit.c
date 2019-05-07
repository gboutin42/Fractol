/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:27:27 by gboutin           #+#    #+#             */
/*   Updated: 2018/12/06 17:42:10 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncpy_end(char *dst, char const *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	dst[i] = 0;
	return (dst);
}

static int		ft_is_sep(char const str, char c)
{
	if (str == c && str != '\0')
		return (1);
	return (0);
}

static int		ft_count_word(char const *str, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		while (!(str[i] == c) && str[i] != '\0')
			i++;
		while ((str[i] == c) && str[i] != '\0')
			i++;
		word++;
	}
	return (word);
}

static int		ft_let(char const *str, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
		{
			i++;
			size++;
			if (str[i] == c)
				return (size);
		}
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		nb_word;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (ft_is_sep(*s, c))
		s++;
	nb_word = ft_count_word(s, c);
	if (!(array = (char**)malloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	while (i < nb_word)
	{
		if (!(array[i] = (char*)malloc(sizeof(char*) * (ft_let(s, c) + 1))))
			return (NULL);
		ft_strncpy_end(array[i], s, ft_let(s, c));
		s += ft_let(s, c);
		while (ft_is_sep(*s, c))
			++s;
		i++;
	}
	array[i] = 0;
	return (array);
}
