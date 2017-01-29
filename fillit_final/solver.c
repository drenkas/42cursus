/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:37:58 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/17 16:37:59 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static	char		**ft_drop(char **blk, t_block *block, int max)
{
	int	x;
	int	y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (blk[y][x] == block->c)
				blk[y][x] = '.';
			x++;
		}
		y++;
	}
	return (blk);
}

static	char		**ft_save(char **blk, t_block *block, int max)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y)
			{
				blk[y][x] = block->c;
				i++;
			}
			x++;
		}
		blk[y][x] = '\0';
		y++;
	}
	blk[y] = NULL;
	return (blk);
}

static	int			ft_check(char **blk, t_block *block, int max)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y && blk[y][x] != '.')
				return (0);
			else if (block->x[i] == x && block->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

char				**ft_solve(char **blk, t_block *block, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!block->next)
		return (blk);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			block = ft_update_coord(block, x, y);
			if (ft_check(blk, block, max))
				tmp = ft_solve(ft_save(blk, block, max), block->next, max);
			if (tmp)
				return (tmp);
			blk = ft_drop(blk, block, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char				**ft_res(t_block *block, int max)
{
	char **blk;

	blk = NULL;
	while (!blk)
	{
		blk = ft_fill(blk, max);
		blk = ft_solve(blk, block, max);
		max++;
	}
	return (blk);
}
