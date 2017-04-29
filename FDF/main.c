/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:39:49 by drenkas           #+#    #+#             */
/*   Updated: 2017/02/24 19:39:50 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_mlx st, t_cob *s)
{
	int		i;
	int		j;
	int		*cord;

	i = 0;
	cord = (int*)malloc(sizeof(int) * 4);
	while (i < s[0].col)
	{
		j = 0;
		while (j < s[i].weidth)
		{
			if ((j + 1) < s[i].weidth)
			{
				cord = arr(s[i].x[j], s[i].y[j], s[i].x[j + 1], s[i].y[j + 1]);
				draw_l(cord, st);
			}
			if ((i + 1) < s[0].col)
			{
				cord = arr(s[i].x[j], s[i].y[j], s[i + 1].x[j], s[i + 1].y[j]);
				draw_l(cord, st);
			}
			j++;
		}
		i++;
	}
}

void	draw_l(int *arr, t_mlx st)
{
	int ar[6];

	ar[0] = abs(arr[2] - arr[0]);
	ar[1] = abs(arr[3] - arr[1]);
	ar[2] = arr[1] < arr[3] ? 1 : -1;
	ar[3] = arr[0] < arr[2] ? 1 : -1;
	ar[4] = ar[0] - ar[1];
	if (arr[2] <= 999 && arr[2] >= 0 && arr[3] >= 0 && arr[3] <= 999)
		st.addr[(arr[2] + (arr[3] * st.s_l / 4)) * 4 + st.color] = 255;
	while (arr[0] != arr[2] || arr[1] != arr[3])
	{
		if (arr[0] <= 999 && arr[0] >= 0 && arr[1] >= 0 && arr[1] <= 999)
			st.addr[(arr[0] + (arr[1] * st.s_l / 4)) * 4 + st.color] = 255;
		ar[5] = ar[4] * 2;
		if (ar[5] > -ar[1])
		{
			ar[4] -= ar[1];
			arr[0] += ar[3];
		}
		if (ar[5] < ar[0])
		{
			ar[4] += ar[0];
			arr[1] += ar[2];
		}
	}
}

void	start_mlx(t_cob *strs)
{
	t_mlx	st;

	st.mlx_ptr = mlx_init();
	st.win_prt = mlx_new_window(st.mlx_ptr, 1000, 1000, "mlx_win");
	st.img_ptr = mlx_new_image(st.mlx_ptr, 1000, 1000);
	st.addr = mlx_get_data_addr(st.img_ptr, &st.bpp, &st.s_l, &st.endian);
	strs = ft_izometr(strs);
	ft_center(strs);
	st.color = 0;
	ft_draw(st, strs);
	st.strs = malloc(sizeof(strs));
	st.strs = strs;
	mlx_hook(st.win_prt, 2, 5, ft_hook, &st);
	st.put = mlx_put_image_to_window(st.mlx_ptr, st.win_prt, st.img_ptr, 0, 0);
	mlx_loop(st.mlx_ptr);
}

void	next_img(t_mlx st)
{
	st.put = mlx_destroy_image(st.mlx_ptr, st.img_ptr);
	st.img_ptr = mlx_new_image(st.mlx_ptr, 1000, 1000);
	st.addr = mlx_get_data_addr(st.img_ptr, &st.bpp, &st.s_l, &st.endian);
	ft_center(st.strs);
	ft_draw(st, st.strs);
	mlx_hook(st.win_prt, 2, 5, ft_hook, &st);
	st.put = mlx_put_image_to_window(st.mlx_ptr, st.win_prt, st.img_ptr, 0, 0);
	mlx_loop(st.mlx_ptr);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		col;
	int		i;
	char	*line;
	t_cob	*strs;

	if (argc != 2)
		exit(1);
	col = 0;
	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(1);
	while (get_next_line(fd, &line) != 0)
		col++;
	fd = close(fd);
	fd = open(argv[1], O_RDONLY);
	strs = (t_cob *)malloc(sizeof(t_cob) * col);
	while (get_next_line(fd, &line) != 0)
	{
		strs[i] = ft_rec_coord(line, strs[i], i);
		strs[i].col = col;
		i++;
	}
	start_mlx(strs);
	return (0);
}
