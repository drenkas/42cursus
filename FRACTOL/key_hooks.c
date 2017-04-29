/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 20:16:55 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/08 20:16:56 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		ft_key_hook(int key, t_mlx *st)
{
	if (key == 53)
	{
		system("killall afplay");
		ft_error("                       THE END\n");
	}
	else if (key >= 123 && key <= 126)
		ft_move(*st, key);
	else if (key == 76)
		ft_music(*st);
	else if (key >= 18 && key <= 23)
		ft_key_color(*st, key);
	else if (key == 8)
		ft_swap_color(*st);
	else if (key >= 83 && key <= 91)
		ft_swap_fract(*st, key);
	else if (key >= 69 && key <= 78)
		ft_next_track(*st, key);
	else if (key >= 24 && key <= 27)
		ft_iterat(*st, key);
	return (0);
}

void	ft_move(t_mlx st, int k)
{
	if (k == 123)
		st.x1 -= st.coef;
	else if (k == 124)
		st.x1 += st.coef;
	else if (k == 126)
		st.y1 -= st.coef;
	else if (k == 125)
		st.y1 += st.coef;
	new_start(st);
}

void	ft_music(t_mlx st)
{
	if (st.msc == 0)
	{
		system(ft_strjoin("afplay ", st.msc_arg));
		st.msc = 1;
	}
	else if (st.msc == 1)
	{
		system("killall afplay");
		st.msc = 0;
	}
	new_start(st);
}

void	ft_key_color(t_mlx st, int k)
{
	if (k == 18)
		st.set_clr = 0;
	else if (k == 19)
		st.set_clr = 1;
	else if (k == 20)
		st.set_clr = 2;
	else if (k == 21)
		st.set_clr = 3;
	else if (k == 23)
		st.set_clr = 4;
	else if (k == 22)
		st.set_clr = 5;
	new_start(st);
}

void	ft_swap_color(t_mlx st)
{
	if (st.set_clr < 5)
		st.set_clr++;
	else
		st.set_clr = 0;
	new_start(st);
}
