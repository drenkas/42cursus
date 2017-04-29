/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:24:19 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/09 15:24:19 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_menu(t_mlx st)
{
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 75, 0xbcdf46, "+/- ITER: + | -");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 100, 0xbcdf46, ft_strjoin("ITER: ", ft_itoa(st.iter)));
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 125, 0xbcdf46, "Swap Fract (NUM1 - Mandelbrot, NUM2 - Julia, NUM3 - Burning Ship, NUM4 - Brain");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 275, 0xbcdf46, "STOP rotate (julia and brain): MK3");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 250, 0xbcdf46, "ZOOM: LMK - UP , RMK -  DOWN");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 225, 0xbcdf46, "Change Color (1 | 2 | 3 | 4)");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 200, 0xbcdf46, "Swap Color (C)");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 50, 0xbcdf46, "Move : ARROWS");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 150, 0xbcdf46, "Play/Stop Music : NUM ENTER");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 175, 0xbcdf46, "Change Music : NUM+ | NUM-");
}
