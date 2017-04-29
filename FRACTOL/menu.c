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

static t_mlx	ft_clr_text(t_mlx st)
{
	if (st.set_clr == 0 || st.set_clr == 1 || st.set_clr == 4)
		st.color_txt = 0xbcdf46;
	else
		st.color_txt = 0x0203db;
	return (st);
}

void			ft_menu(t_mlx st)
{
	char *s[11];

	st = ft_clr_text(st);
	s[0] = ft_strdup("| +/- ITER: + | -                      |");
	s[1] = ft_strdup(ft_strjoin("| ITER: ", ft_itoa(st.iter)));
	s[2] = ft_strdup("| Swap Fract(NUM1 - NUM8)              |");
	s[3] = ft_strdup("| STOP rotate (julia and brain): MK3   |");
	s[4] = ft_strdup("| ZOOM: LMK - UP , RMK -  DOWN         |");
	s[5] = ft_strdup("| Change Color (1 | 2 | 3 | 4 | 5 | 6) |");
	s[6] = ft_strdup("| Swap Color (C)                       |");
	s[7] = ft_strdup("| Move : ARROWS                        |");
	s[8] = ft_strdup("| Play/Stop Music : NUM ENTER          |");
	s[9] = ft_strdup("| Change Music : NUM+ | NUM-           |");
	s[10] = ft_strdup("----------------------------------------");
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 75, st.color_txt, s[0]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 100, st.color_txt, s[1]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 125, st.color_txt, s[2]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 275, st.color_txt, s[3]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 250, st.color_txt, s[4]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 225, st.color_txt, s[5]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 200, st.color_txt, s[6]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 50, st.color_txt, s[7]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 150, st.color_txt, s[8]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 175, st.color_txt, s[9]);
	mlx_string_put(st.mlx_ptr, st.win_prt, 10, 300, st.color_txt, s[10]);
}

void			error_menu(void)
{
	ft_putstr(RED);
	ft_putstr("No arguments! Pls give me:\n");
	ft_putstr(OK);
	ft_putstr("1)M - Mandelbrot\n2)J - Julia\n3)BS - Burning ");
	ft_putstr("Ship(Shit)\n4)Br - Brain(but it is not exactly)\n");
	ft_putstr("5)T - Tricorn\n6)C - Celtic\n7)P - Perp. Burning Ship\n");
	ft_putstr("8)F - Fake Tricorn\n");
	exit(1);
}
