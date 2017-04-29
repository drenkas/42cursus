/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:43:45 by drenkas           #+#    #+#             */
/*   Updated: 2017/02/24 19:43:46 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# define RED "\033[02;31m"
# define OK "\033[32m"

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_prt;
	void				*img_ptr;
	int					bpp;
	int					s_l;
	int					endian;
	char				*addr;
	int					put;
	int					point;
	char				*arg;
	int					msc;
	int					msc_p;
	char				*msc_arg;
	int					check;
	int					stop;
	int					set_clr;
	double				coef;

	double				im_hight;
	double				im_weidth;
	double				zr;
	double				zi;
	double				iter;
	double				cr;
	double				ci;
	double				x1_s;
	double				y1_s;
	double				x2_s;
	double				y2_s;
	double				x1;
	double				y1;
	double				x2;
	double				y2;
	int					i;
	double				x;
	double				y;

	double				zoom;
	double				zoom_s;
	double				zoom_tmp;
	double				tmp;

	int					color1;
	int					color2;
	int					color3;
	int					color_txt;
}						t_mlx;

void					start_mlx(t_mlx st);
void					new_start(t_mlx st);
void					ft_menu(t_mlx st);
t_mlx					check_arg(t_mlx st);
t_mlx					mandel(t_mlx st);
t_mlx					init_mandel(t_mlx st);
t_mlx					init_julia(t_mlx st);
t_mlx					julia(t_mlx st);
t_mlx					init_burnship(t_mlx st);
t_mlx					burnship(t_mlx st);
t_mlx					brain(t_mlx st);
t_mlx					init_brain(t_mlx st);
t_mlx					fract_init(t_mlx st);
void					draw(t_mlx st);
void					draw_black(t_mlx st);
void					change_draw(t_mlx st);
t_mlx					tricorn(t_mlx st);
t_mlx					init_tricorn(t_mlx st);
t_mlx					init_celtic(t_mlx st);
t_mlx					celtic(t_mlx st);
t_mlx					init_perpbs(t_mlx st);
t_mlx					perpbs(t_mlx st);
t_mlx					init_ftricorn(t_mlx s);
t_mlx					ftricorn(t_mlx s);

t_mlx					change_color(t_mlx st);
void					ft_key_color(t_mlx st, int k);
void					ft_swap_color(t_mlx st);
t_mlx					ft_color4(t_mlx st);
t_mlx					ft_color5(t_mlx st);

int						ft_key_hook(int key, t_mlx *st);
int						ft_exit(t_mlx *st);
void					ft_iterat(t_mlx st, int k);
void					ft_swap_fract(t_mlx st, int k);
int						mouse_zoom(int k, int x, int y, t_mlx *st);
t_mlx					ft_stop(t_mlx st, int k);
void					ft_move(t_mlx st, int k);
int						ft_mouse(int x, int y, t_mlx *st);
void					ft_music(t_mlx st);
void					ft_next_track(t_mlx st, int k);
t_mlx					charge_msc(t_mlx st);
void					error_menu(void);

#endif
