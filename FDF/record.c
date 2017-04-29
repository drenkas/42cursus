/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:57:22 by drenkas           #+#    #+#             */
/*   Updated: 2017/02/26 18:57:23 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cob	ft_rec_coord(char *line, t_cob strs, int hg)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	strs.weidth = ft_doublearrsize(nums);
	strs.x = (double *)malloc(sizeof(double) * strs.weidth);
	strs.z = (double *)malloc(sizeof(double) * strs.weidth);
	strs.y = (double *)malloc(sizeof(double) * strs.weidth);
	while (nums[i] != '\0')
	{
		strs.x[i] = i * 20;
		strs.y[i] = hg * 20;
		strs.z[i] = ft_atoi(nums[i]) * 20;
		i++;
	}
	return (strs);
}

t_cob	*ft_izometr(t_cob *st)
{
	int i;
	int j;

	i = 0;
	while (i < st[0].col)
	{
		j = 0;
		while (j < st[i].weidth)
		{
			st[i].x[j] = (st[i].x[j] - st[i].z[j]) * (sqrt(3) / sqrt(6));
			st[i].y[j] = (st[i].x[j] + 2 * st[i].y[j] + st[i].z[j]) / sqrt(6);
			j++;
		}
		i++;
	}
	return (st);
}

void	ft_center(t_cob *st)
{
	double	x;
	double	y;
	int		j;
	int		i;

	x = (st[st[0].col - 1].x[st[st[0].col - 1].weidth - 1] + st[0].x[0]) / 2;
	y = (st[st[0].col - 1].y[st[st[0].col - 1].weidth - 1] + st[0].y[0]) / 2;
	i = 0;
	while (i < st[0].col)
	{
		j = 0;
		while (j < st[i].weidth)
		{
			st[i].x[j] += 500 - x;
			st[i].y[j] += 500 - y;
			j++;
		}
		i++;
	}
}

void	ft_color(t_mlx st)
{
	if (st.color <= 1)
		st.color++;
	else
		st.color = 0;
	next_img(st);
}

int		*arr(int x1, int y1, int x2, int y2)
{
	int *ar;

	ar = (int*)malloc(sizeof(int) * 4);
	ar[0] = x1;
	ar[1] = y1;
	ar[2] = x2;
	ar[3] = y2;
	return (ar);
}
