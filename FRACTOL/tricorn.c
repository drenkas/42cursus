/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mande5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:51:48 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/18 17:51:49 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static t_mlx	init_tri_xy(t_mlx st)
{
	st.x1 = -2.2;
	st.y1 = -1.9;
	st.x2 = 0.5;
	st.y2 = 1.25;
	st.zoom = st.im_hight / (st.x2 - st.x1) / 1.4;
	st.zoom_s = st.im_weidth / (st.y2 - st.y1) / 1.4;
	st.put = 1;
	return (st);
}

t_mlx			tricorn(t_mlx st)
{
	st.x = 0;
	st.i = 0;
	st.stop = 1;
	if (st.put == 0)
		st = init_tri_xy(st);
	return (st);
}

t_mlx			init_tricorn(t_mlx st)
{
	st = tricorn(st);
	while (st.x < st.im_weidth)
	{
		st.y = 0;
		while (st.y < st.im_hight)
		{
			st.cr = (st.x / st.zoom + st.x1);
			st.ci = (st.y / st.zoom_s + st.y1);
			st.zr = 0;
			st.zi = 0;
			st.i = 0;
			while (st.zr * st.zr + st.zi * st.zi < 4 && st.i < st.iter)
			{
				st.tmp = st.zr;
				st.zr = st.zr * st.zr - st.zi * st.zi + st.cr;
				st.zi = -2 * st.zi * st.tmp + st.ci;
				st.i++;
			}
			change_draw(st);
			st.y++;
		}
		st.x++;
	}
	return (st);
}
