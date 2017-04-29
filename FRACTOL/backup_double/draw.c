/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:09:12 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/11 20:09:13 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	change_draw(t_mlx st)
{
	if (st.i == st.iter)
		draw_black(st);
	else
		draw(st);
}

void	draw_black(t_mlx st)
{
	int i;

	i = st.s_l * st.y + st.x * 4;
	st.addr[i] = mlx_get_color_value(st.mlx_ptr, 0x000000);
	st.addr[i + 1] = mlx_get_color_value(st.mlx_ptr, 0x000000);
	st.addr[i + 2] = mlx_get_color_value(st.mlx_ptr, 0x000000);
}

void	draw(t_mlx st)
{
	int i;

	st =  change_color(st);
	i = st.s_l * st.y + st.x * 4;
	st.addr[i] = mlx_get_color_value(st.mlx_ptr, st.i * st.color1);
	st.addr[i + 1] = mlx_get_color_value(st.mlx_ptr, st.i * st.color2);
	st.addr[i + 2] = mlx_get_color_value(st.mlx_ptr, st.i * st.color3);
}
