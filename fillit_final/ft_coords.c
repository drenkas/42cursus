/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:36:55 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/17 16:36:55 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

t_block				*ft_update_coord(t_block *block, int x, int y)
{
	int xmin;
	int ymin;
	int i;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i != 4)
	{
		if (block->x[i] < xmin)
			xmin = block->x[i];
		if (block->y[i] < ymin)
			ymin = block->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		block->x[i] = block->x[i] - xmin + x;
		block->y[i] = block->y[i] - ymin + y;
		i++;
	}
	return (block);
}

static t_block		*ft_block_coord(t_block *block, char **s)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				block->x[i] = x;
				block->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (block);
}

t_block				*ft_default_coord(t_block *block)
{
	t_block *tmp;

	tmp = block;
	while (block->next)
	{
		block = ft_block_coord(block, ft_strsplit(block->str, '\n'));
		free(block->str);
		block = block->next;
	}
	return (tmp);
}
