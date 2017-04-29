/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:39:21 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/13 17:39:22 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static t_mlx	init_br_xy(t_mlx st)
{
	st.x1 = -1.4;
	st.y1 = -1.4;
	st.x2 = 1;
	st.y2 = 1;
	st.cr = 0.35;
	st.ci = 0.04;
	st.zoom = st.im_hight / (st.x2 - st.x1) / 1.3;
	st.zoom_s = st.im_weidth / (st.y2 - st.y1) / 1.3;
	st.put = 1;
	return (st);
}

t_mlx			brain(t_mlx st)
{
	st.x = 0;
	if (st.put == 0)
		st = init_br_xy(st);
	return (st);
}

t_mlx			init_brain(t_mlx st)
{
	st = brain(st);
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
				st.zr = fabs(st.zr * st.zr - st.zi * st.zi + st.cr);
				st.zi = fabs(2 * st.zi * st.tmp + st.ci);
				st.i++;
			}
			change_draw(st);
			st.y++;
		}
		st.x++;
	}
	return (st);
}
