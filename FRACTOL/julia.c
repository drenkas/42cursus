/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:50:26 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/12 18:50:27 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static t_mlx	init_j_xy(t_mlx st)
{
	st.x1 = -1.4;
	st.y1 = -1.4;
	st.x2 = 1;
	st.y2 = 1;
	st.cr = 0.13;
	st.ci = 0.68;
	st.zoom = st.im_hight / (st.x2 - st.x1) / 1.2;
	st.zoom_s = st.im_weidth / (st.y2 - st.y1) / 1.2;
	st.put = 1;
	return (st);
}

t_mlx			julia(t_mlx st)
{
	st.x = 0;
	if (st.put == 0)
		st = init_j_xy(st);
	return (st);
}

t_mlx			init_julia(t_mlx st)
{
	st = julia(st);
	while (st.x < st.im_weidth)
	{
		st.y = 0;
		while (st.y < st.im_hight)
		{
			st.i = 0;
			st.zr = (st.x / st.zoom + st.x1);
			st.zi = (st.y / st.zoom_s + st.y1);
			while (st.zr * st.zr + st.zi * st.zi < 4 && st.i < st.iter)
			{
				st.tmp = st.zr;
				st.zr = st.zr * st.zr - st.zi * st.zi + st.cr;
				st.zi = 2 * st.zi * st.tmp + st.ci;
				st.i++;
			}
			change_draw(st);
			st.y++;
		}
		st.x++;
	}
	return (st);
}
