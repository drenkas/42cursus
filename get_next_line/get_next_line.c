/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:35:36 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/28 20:35:37 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*my_lstnew(char *content, int fd)
{
	t_lst	*tmp;

	if (!(tmp = malloc(sizeof(t_lst))))
		return (NULL);
	tmp->content = ft_strcpy(ft_strnew(ft_strlen(content)), content);
	tmp->fd = fd;
	tmp->next = NULL;
	return (tmp);
}

int		check(t_lst *list, char **line, int c)
{
	char	*n;

	n = ft_strchr(list->content, '\n');
	if (n == NULL && c == 0 && list->content[0] != '\0')
	{
		*line = ft_strcpy(ft_strnew(ft_strlen(list->content)), list->content);
		free(list->content);
		return (1);
	}
	if (c == 0 && list->content[0] == '\0')
	{
		free(list->content);
		return (0);
	}
	*line = ft_strncpy(ft_strnew(n - list->content), list->content, \
	n - list->content);
	list->content = ft_strcpy(ft_strnew(ft_strlen(n)), n + 1);
	return (1);
}

int		ft_fynorm(char *buf, int fd, char **line, t_lst *list)
{
	int c;

	c = 0;
	while ((c = read(fd, buf, BUFF_SIZE)) > -1 && BUFF_SIZE < 65536)
	{
		while (list->next && list->fd != fd && list != NULL)
			list = list->next;
		if (list == NULL)
			list = my_lstnew(buf, fd);
		else if (list->next == NULL && list->fd != fd)
		{
			list->next = my_lstnew(buf, fd);
			list = list->next;
		}
		else if (list->content == NULL && c == 0)
			return (0);
		else
			list->content = ft_strjoin(list->content, buf);
		if (ft_strchr(list->content, '\n') || c == 0)
			return (check(list, line, c));
		ft_strclr(buf);
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	static t_lst	listcontent;
	t_lst			*list;

	list = &listcontent;
	buf = ft_strnew(BUFF_SIZE);
	return (ft_fynorm(buf, fd, line, list));
}
