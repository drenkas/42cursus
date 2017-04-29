/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:19:13 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/17 15:19:13 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_mlx	ft_color4(t_mlx st)
{
	st.color1 = 0x0F0F0F;
	st.color2 = 0x00A000;
	st.color3 = 0xA000;
	return (st);
}

t_mlx	ft_color5(t_mlx st)
{
	st.color1 = 0x5F0255;
	st.color2 = 0x5F0250;
	st.color3 = 0x5F0055;
	return (st);
}
