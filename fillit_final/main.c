/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:37:16 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/17 16:37:16 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

void		ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

t_block		*ft_store(char *str)
{
	int		i;
	int		j;
	char	c;
	t_block *block;
	t_block *tmp;

	j = 0;
	c = 64;
	i = ft_early_valid(str);
	if (!(block = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	tmp = block;
	while (i-- > 0)
	{
		tmp->str = ft_strndup(&str[j], 20);
		ft_ultcheck(tmp->str);
		tmp->c = ++c;
		j += 21;
		if (!(tmp->next = (t_block *)malloc(sizeof(t_block))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (block);
}

char		*ft_read(char *file)
{
	int		fd;
	int		read_b;
	int		i;
	char	tmp[1024];
	char	buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while ((read_b = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
		if (i > 1024)
			ft_error();
	}
	tmp[i] = '\0';
	return (ft_strdup(tmp));
}

int			main(int argc, char *argv[])
{
	t_block		*block;
	char		*readf;
	char		**result;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [file name]");
		exit(0);
	}
	else
	{
		readf = ft_read(argv[1]);
		block = ft_store(readf);
		block = ft_default_coord(block);
		result = ft_res(block, ft_max_size(block));
		free(block);
		while (*result)
			ft_putendl(*result++);
	}
	return (0);
}
