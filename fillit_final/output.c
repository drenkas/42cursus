/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:37:39 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/19 15:36:00 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

char		**ft_fill(char **blk, int max)
{
	int x;
	int y;

	y = 0;
	if (!(blk = (char **)malloc(sizeof(char *) * max + 1)))
		return (NULL);
	while (y < max)
	{
		blk[y] = ft_strnew(max);
		x = 0;
		while (x < max)
		{
			blk[y][x] = '.';
			x++;
		}
		y++;
	}
	blk[y] = NULL;
	return (blk);
}
