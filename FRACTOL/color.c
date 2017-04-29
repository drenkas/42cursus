/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:19:24 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/13 18:19:25 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static t_mlx	ft_color0(t_mlx st)
{
	st.color1 = 0x000000;
	st.color2 = 0x000000;
	st.color3 = 0x060000 >> 16;
	return (st);
}

static t_mlx	ft_color1(t_mlx st)
{
	st.color1 = 0x000000;
	st.color2 = 0x000500 >> 8;
	st.color3 = 0x000000;
	return (st);
}

static t_mlx	ft_color2(t_mlx st)
{
	st.color1 = 0x000009;
	st.color2 = 0x0F0F0F * 500;
	st.color3 = 0xF00F0F;
	return (st);
}

static t_mlx	ft_color3(t_mlx st)
{
	st.color1 = 0x0000FF0;
	st.color2 = 0x0F00F0 * 500 >> 8;
	st.color3 = 0x0F00F0 * 1000 >> 16;
	return (st);
}

t_mlx			change_color(t_mlx st)
{
	if (st.set_clr == 0)
		st = ft_color0(st);
	else if (st.set_clr == 1)
		st = ft_color1(st);
	else if (st.set_clr == 2)
		st = ft_color2(st);
	else if (st.set_clr == 3)
		st = ft_color3(st);
	else if (st.set_clr == 4)
		st = ft_color4(st);
	else if (st.set_clr == 5)
		st = ft_color5(st);
	return (st);
}
