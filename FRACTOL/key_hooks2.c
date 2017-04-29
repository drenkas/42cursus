/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:27:27 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/13 20:27:28 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_swap_fract(t_mlx st, int k)
{
	ft_strclr(st.arg);
	st = fract_init(st);
	if (k == 83)
		st.point = 1;
	else if (k == 84)
		st.point = 2;
	else if (k == 85)
		st.point = 3;
	else if (k == 86)
		st.point = 4;
	else if (k == 87)
		st.point = 5;
	else if (k == 88)
		st.point = 6;
	else if (k == 89)
		st.point = 7;
	else if (k == 91)
		st.point = 8;
	new_start(st);
}

void	ft_iterat(t_mlx st, int k)
{
	if (k == 24)
		st.iter += 10;
	else if (k == 27)
		st.iter -= 10;
	new_start(st);
}

int		ft_exit(t_mlx *st)
{
	st->msc = 0;
	system("killall afplay");
	ft_error("                       THE END\n");
	return (0);
}
