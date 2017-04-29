/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:38:13 by drenkas           #+#    #+#             */
/*   Updated: 2017/03/30 15:38:13 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_mlx	check_arg(t_mlx st)
{
	if (ft_strcmp(st.arg, "M") == 0 || st.point == 1)
		st = init_mandel(st);
	else if (ft_strcmp(st.arg, "J") == 0 || st.point == 2)
		st = init_julia(st);
	else if (ft_strcmp(st.arg, "BS") == 0 || st.point == 3)
		st = init_burnship(st);
	else if (ft_strcmp(st.arg, "Br") == 0 || st.point == 4)
		st = init_brain(st);
	else if (ft_strcmp(st.arg, "T") == 0 || st.point == 5)
		st = init_tricorn(st);
	else if (ft_strcmp(st.arg, "C") == 0 || st.point == 6)
		st = init_celtic(st);
	else if (ft_strcmp(st.arg, "P") == 0 || st.point == 7)
		st = init_perpbs(st);
	else if (ft_strcmp(st.arg, "F") == 0 || st.point == 8)
		st = init_ftricorn(st);
	else
		error_menu();
	return (st);
}

t_mlx	fract_init(t_mlx st)
{
	st.x1_s = 0;
	st.y1_s = 0;
	st.x2_s = 0;
	st.y2_s = 0;
	st.iter = 50;
	st.im_hight = 1000;
	st.im_weidth = 1000;
	st.ci = 0;
	st.cr = 0;
	st.zoom_s = 0;
	st.msc = 0;
	st.check = 0;
	st.stop = 0;
	st.set_clr = 0;
	st.msc_p = 0;
	st.msc_arg = ft_strdup("./music/raka_taka.mp3 &");
	st.coef = 0.1;
	st.put = 0;
	st.color_txt = 0xbcdf46;
	return (st);
}

void	new_start(t_mlx st)
{
	mlx_destroy_image(st.mlx_ptr, st.img_ptr);
	st.img_ptr = mlx_new_image(st.mlx_ptr, st.im_weidth, st.im_weidth);
	st.addr = mlx_get_data_addr(st.img_ptr, &st.bpp, &st.s_l, &st.endian);
	st = check_arg(st);
	mlx_put_image_to_window(st.mlx_ptr, st.win_prt, st.img_ptr, 0, 0);
	ft_menu(st);
	mlx_hook(st.win_prt, 2, 5, ft_key_hook, &st);
	mlx_mouse_hook(st.win_prt, mouse_zoom, &st);
	mlx_hook(st.win_prt, 6, 1L << 6, ft_mouse, &st);
	mlx_hook(st.win_prt, 17, (1L << 17), ft_exit, &st);
	mlx_loop(st.mlx_ptr);
}

void	start_mlx(t_mlx st)
{
	st.mlx_ptr = mlx_init();
	st.win_prt = mlx_new_window(st.mlx_ptr, 1000, 1000, "Fract'ol");
	st.img_ptr = mlx_new_image(st.mlx_ptr, st.im_weidth, st.im_weidth);
	st.addr = mlx_get_data_addr(st.img_ptr, &st.bpp, &st.s_l, &st.endian);
	st = check_arg(st);
	mlx_put_image_to_window(st.mlx_ptr, st.win_prt, st.img_ptr, 0, 0);
	ft_menu(st);
	mlx_hook(st.win_prt, 2, 5, ft_key_hook, &st);
	mlx_mouse_hook(st.win_prt, mouse_zoom, &st);
	mlx_hook(st.win_prt, 6, 1L << 6, ft_mouse, &st);
	mlx_hook(st.win_prt, 17, (1L << 17), ft_exit, &st);
	mlx_loop(st.mlx_ptr);
}

int		main(int ac, char *av[])
{
	t_mlx	strs;

	if (ac != 2)
		error_menu();
	if (!(strs.arg = (char*)malloc(sizeof(char) * ft_strlen(av[1]))))
		ft_error("Fail malloc\n");
	ft_strcpy(strs.arg, av[1]);
	strs = fract_init(strs);
	start_mlx(strs);
	return (0);
}
