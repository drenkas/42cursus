/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:59:24 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/09 16:59:25 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		mouse_zoom(int k, int x, int y, t_mlx *st)
{
	if (k == 2 || k == 5 || k == 1 || k == 4)
	{
		if (x >= 0 && x <= st->im_weidth && y >= 0 && y <= st->im_weidth)
		{
			st->check = 1;
			st->x1_s = st->x1 + x / st->zoom;
			st->y1_s = st->y1 + y / st->zoom;
			if (k == 2 || k == 5)
				st->zoom_s /= 2;
			else if (k == 1 || k == 4)
				st->zoom_s += st->zoom / 3;
			new_start(*st);
		}
	}
	else if (k == 3 && st->stop == 0)
		st->stop = 1;
	else if (k == 3 && st->stop != 0)
		st->stop = 0;
	return (0);
}

int		ft_mouse(int x, int y, t_mlx *st)
{
	if (x >= 0 && x <= 1000 && y >= 0 && y <= 1000 && st->stop != 1)
	{
		st->check = 1;
		st->cr = x / 1000.0;
		st->ci = y / 1000.0;
	}
	new_start(*st);
	return (0);
}
