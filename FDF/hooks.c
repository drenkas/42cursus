/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:02:19 by drenkas           #+#    #+#             */
/*   Updated: 2017/03/08 17:02:19 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_hook(int key, t_mlx *st)
{
	if (key == 53)
		exit(1);
	if (key == 24)
		ft_zoom(*st, 1);
	else if (key == 27)
		ft_zoom(*st, 0);
	else if (key == 86)
		ft_turn_z(*st, 1);
	else if (key == 88)
		ft_turn_z(*st, 0);
	else if (key == 85)
		ft_turn_x(*st, 1);
	else if (key == 83)
		ft_turn_x(*st, 0);
	else if (key == 87)
		ft_turn_y(*st, 1);
	else if (key == 84)
		ft_turn_y(*st, 0);
	else if (key == 92)
		ft_color(*st);
	return (0);
}

void	ft_zoom(t_mlx st, int n)
{
	int i[2];

	i[0] = 0;
	while (i[0] < st.strs[0].col)
	{
		i[1] = 0;
		while (i[1] < st.strs[i[0]].weidth)
		{
			if (n == 1)
			{
				st.strs[i[0]].x[i[1]] *= 1.1;
				st.strs[i[0]].y[i[1]] *= 1.1;
				st.strs[i[0]].z[i[1]] *= 1.1;
			}
			else
			{
				st.strs[i[0]].x[i[1]] /= 1.1;
				st.strs[i[0]].y[i[1]] /= 1.1;
				st.strs[i[0]].z[i[1]] /= 1.1;
			}
			i[1]++;
		}
		i[0]++;
	}
	next_img(st);
}

void	ft_turn_z(t_mlx st, int n)
{
	int i[2];

	i[0] = 0;
	while (i[0] < st.strs[0].col)
	{
		i[1] = 0;
		while (i[1] < st.strs[i[0]].weidth)
		{
			st.x = st.strs[i[0]].x[i[1]];
			st.y = st.strs[i[0]].y[i[1]];
			if (n == 1)
			{
				st.strs[i[0]].x[i[1]] = st.x * cos(D) - st.y * sin(D);
				st.strs[i[0]].y[i[1]] = st.x * sin(D) + st.y * cos(D);
			}
			else if (n == 0)
			{
				st.strs[i[0]].x[i[1]] = (st.x * cos(-D) - st.y * sin(-D));
				st.strs[i[0]].y[i[1]] = (st.x * sin(-D) + st.y * cos(-D));
			}
			i[1]++;
		}
		i[0]++;
	}
	next_img(st);
}

void	ft_turn_x(t_mlx st, int n)
{
	int	i[2];

	i[0] = 0;
	while (i[0] < st.strs[0].col)
	{
		i[1] = 0;
		while (i[1] < st.strs[i[0]].weidth)
		{
			st.z = st.strs[i[0]].z[i[1]];
			st.y = st.strs[i[0]].y[i[1]];
			if (n == 1)
			{
				st.strs[i[0]].z[i[1]] = -st.y * sin(D) + st.z * cos(D);
				st.strs[i[0]].y[i[1]] = st.z * sin(D) + st.y * cos(D);
			}
			else if (n == 0)
			{
				st.strs[i[0]].z[i[1]] = -st.y * sin(-D) + st.z * cos(-D);
				st.strs[i[0]].y[i[1]] = st.z * sin(-D) + st.y * cos(-D);
			}
			i[1]++;
		}
		i[0]++;
	}
	next_img(st);
}

void	ft_turn_y(t_mlx st, int n)
{
	int i[2];

	i[0] = 0;
	while (i[0] < st.strs[0].col)
	{
		i[1] = 0;
		while (i[1] < st.strs[i[0]].weidth)
		{
			st.x = st.strs[i[0]].x[i[1]];
			st.z = st.strs[i[0]].z[i[1]];
			if (n == 1)
			{
				st.strs[i[0]].x[i[1]] = st.x * cos(D) + st.z * sin(D);
				st.strs[i[0]].z[i[1]] = -st.x * sin(D) + st.z * cos(D);
			}
			else if (n == 0)
			{
				st.strs[i[0]].x[i[1]] = st.x * cos(-D) + st.z * sin(-D);
				st.strs[i[0]].z[i[1]] = -st.x * sin(-D) + st.z * cos(-D);
			}
			i[1]++;
		}
		i[0]++;
	}
	next_img(st);
}
