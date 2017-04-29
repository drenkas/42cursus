/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:36:00 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/06 18:36:00 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_mlx	mandel(t_mlx st)
{
	printf("iter: %f\n", st.iter);
	st.zoom =  st.zoom_s + st.zoom_tmp;
	st.x = 0;
	st.i = 0;
	st.stop = 1;
	if (st.check == 0)
	{
		st.x1 = -2.0 + st.x1_s;
		st.y1 = -1.5 + st.y1_s;
	}
	else
	{
		st.x1 = st.x1_s - (st.im_weidth / st.zoom) / 2;
		st.y1 = st.y1_s - (st.im_hight / st.zoom) / 2;
	}
	return (st);
}

t_mlx	init_mandel(t_mlx st)
{
	st = mandel(st);
	while(st.x < st.im_weidth)
	{
		st.y = 0;
		while (st.y < st.im_hight)
		{
			st.cr = (st.x / st.zoom + st.x1);
			st.ci = (st.y / st.zoom + st.y1);
			st.zr = 0;
			st.zi = 0;
			st.i = 0;
			while(st.zr * st.zr + st.zi * st.zi < 4 && st.i < st.iter)
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
