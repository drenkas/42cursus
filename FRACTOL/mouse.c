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
	if (x >= 0 && x <= st->im_weidth && y >= 0 && y <= st->im_weidth &&
	(k == 2 || k == 5 || k == 1 || k == 4))
	{
		st->x1_s = st->zoom;
		st->y1_s = st->zoom_s;
		if ((k == 2 || k == 5) && st->zoom_s > 140 && st->zoom > 155)
		{
			st->zoom_s /= 1.1;
			st->zoom /= 1.1;
			st->coef *= 1.1;
		}
		else if (k == 1 || k == 4)
		{
			st->zoom_s *= 1.1;
			st->zoom *= 1.1;
			st->coef /= 1.1;
		}
		st->x1 += x / st->x1_s - (x / st->zoom);
		st->y1 += y / st->y1_s - (y / st->zoom_s);
		new_start(*st);
	}
	else if (k == 3)
		*st = ft_stop(*st, k);
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

t_mlx	ft_stop(t_mlx st, int k)
{
	if (k == 3 && st.stop == 0)
		st.stop = 1;
	else if (k == 3 && st.stop != 0)
		st.stop = 0;
	return (st);
}
