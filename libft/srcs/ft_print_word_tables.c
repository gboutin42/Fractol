/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word_tables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:24:36 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/26 10:47:18 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables(char **tab)
{
	int i;

	i = -1;
	while (tab[++i] != '\0')
	{
		ft_putstr(tab[i]);
		ft_putchar(' ');
	}
}
