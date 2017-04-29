/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:52:04 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/18 18:52:04 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static double	sq(double a)
{
	double res;

	res = a * a;
	return (res);
}

static t_mlx	init_ftri_xy(t_mlx s)
{
	s.x1 = -2.2;
	s.y1 = -1.9;
	s.x2 = 0.5;
	s.y2 = 1.25;
	s.zoom = s.im_hight / (s.x2 - s.x1) / 1.4;
	s.zoom_s = s.im_weidth / (s.y2 - s.y1) / 1.4;
	s.put = 1;
	return (s);
}

t_mlx			ftricorn(t_mlx s)
{
	s.x = 0;
	s.i = 0;
	s.stop = 1;
	if (s.put == 0)
		s = init_ftri_xy(s);
	return (s);
}

t_mlx			init_ftricorn(t_mlx s)
{
	s = ftricorn(s);
	while (s.x < s.im_weidth)
	{
		s.y = 0;
		while (s.y < s.im_hight)
		{
			s.cr = (s.x / s.zoom + s.x1);
			s.ci = (s.y / s.zoom_s + s.y1);
			s.zr = 0;
			s.zi = 0;
			s.i = 0;
			while (s.zr * s.zr + s.zi * s.zi < 4 && s.i < s.iter)
			{
				s.tmp = s.zi;
				s.zi = (s.zr * s.zr * 3 - (s.zi * s.zi)) * fabs(s.zi) + s.ci;
				s.zr = ((sq(s.zr)) - (s.tmp * s.tmp * 3)) * fabs(s.zr) + s.cr;
				s.i++;
			}
			change_draw(s);
			s.y++;
		}
		s.x++;
	}
	return (s);
}
