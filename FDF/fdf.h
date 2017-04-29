/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:43:45 by drenkas           #+#    #+#             */
/*   Updated: 2017/02/24 19:43:46 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 100

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "mlx.h"
# include <math.h>
# define D 3.14/30

typedef	struct			s_lst
{
	char				*content;
	int					fd;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_cob
{
	int					weidth;
	double				*x;
	double				*y;
	double				*z;
	int					col;
}						t_cob;

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
	t_cob				*strs;
	int					color;
	double				x;
	double				y;
	double				z;
}						t_mlx;

int						get_next_line(const int fd, char **line);
void					ft_error(void);
int						ft_doublearrsize(char **str);
t_cob					ft_rec_coord(char *line, t_cob strs, int hg);
void					start_mlx(t_cob *strs);
void					ft_draw(t_mlx st, t_cob *strs);
void					draw_l(int *arr, t_mlx st);
t_cob					*ft_izometr(t_cob *strs);
int						ft_hook(int key, t_mlx *st);
void					ft_zoom(t_mlx st, int n);
void					next_img(t_mlx st);
void					ft_center(t_cob *strs);
void					ft_turn_z(t_mlx st, int n);
void					ft_turn_x(t_mlx st, int n);
void					ft_turn_y(t_mlx st, int n);
void					ft_color(t_mlx st);
int						*arr(int x1, int y1, int x2, int y2);
void					check_line(char *elem);
int						ch_after_nul(char *elem, int i);
#endif
