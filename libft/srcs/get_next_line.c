/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:03:52 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/02 12:55:05 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			get_errors(int fd, char **line)
{
	char			b[BUFF_SIZE + 1];

	if ((fd < 0 || read(fd, b, 0) < 0 || BUFF_SIZE <= 0 || line == NULL))
		return (1);
	return (0);
}

static char			*get_read(const int fd, char *str, char *buff)
{
	int				ret;

	if (str == NULL && (!(str = ft_strdup(""))))
		return (NULL);
	while (!(ft_strchr(str, '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (buff[0] == 0x00)
			return (NULL);
		buff[ret] = '\0';
		str = ft_strjoinf(&str, &buff, 1);
	}
	ft_strdel(&buff);
	return (str);
}

static t_list		*ft_check_fd(const int fd, t_list **begin)
{
	t_list			*tmp;
	t_list			*new;

	tmp = *begin;
	new = NULL;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = NULL;
	new->content_size = fd;
	ft_lstadd(begin, new);
	return (new);
}

static int			end_of_gnl(t_list **begin)
{
	ft_lstdel(begin, &ft_del_cont);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*begin = NULL;
	char			*tmp;
	char			*buff;
	int				endline;
	t_list			*current;

	*line = NULL;
	if (get_errors(fd, line) == 1 || !(current = ft_check_fd(fd, &begin)) \
		|| !(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if ((CURR = get_read(fd, (char*)CURR, buff)) == NULL)
		return (end_of_gnl(&begin));
	if ((ft_strcmp((char*)CURR, "") == 0) && (read(fd, buff, BUFF_SIZE) == 0))
		return (end_of_gnl(&begin));
	else if ((char*)CURR)
	{
		endline = ft_get_end_line((char*)CURR);
		*line = strsub_gnl((char*)CURR, 0, endline);
		tmp = (((char*)CURR)[endline] == '\0') \
			? ft_strdup(((char*)CURR) + endline) \
			: ft_strdup(((char*)CURR) + endline + 1);
		ft_strdel((char**)&CURR);
		CURR = tmp;
	}
	return (1);
}
