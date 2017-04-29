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
	char *s[10];

	s[0] = ft_strdup("+/- ITER: + | -");
	s[1] = ft_strdup(ft_strjoin("ITER: ", ft_itoa(st.iter)));
	s[2] = ft_strdup("Swap Fract(N1 - Mandel, N2 - Julia, N3 - BS, N4 - Br");
	s[3] = ft_strdup("STOP rotate (julia and brain): MK3");
	s[4] = ft_strdup("ZOOM: LMK - UP , RMK -  DOWN");
	s[5] = ft_strdup("Change Color (1 | 2 | 3 | 4 | 5 | 6)");
	s[6] = ft_strdup("Swap Color (C)");
	s[7] = ft_strdup("Move : ARROWS");
	s[8] = ft_strdup("Play/Stop Music : NUM ENTER");
	s[9] = ft_strdup("Change Music : NUM+ | NUM-");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 75, 0xbcdf46, s[0]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 100, 0xbcdf46, s[1]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 125, 0xbcdf46, s[2]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 275, 0xbcdf46, s[3]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 250, 0xbcdf46, s[4]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 225, 0xbcdf46, s[5]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 200, 0xbcdf46, s[6]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 50, 0xbcdf46, s[7]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 150, 0xbcdf46, s[8]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 175, 0xbcdf46, s[9]);
}
