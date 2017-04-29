/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:42:02 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/17 15:42:02 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_next_track(t_mlx st, int k)
{
	if (k == 69)
		st.msc_p++;
	else if (k == 78)
		st.msc_p--;
	if (st.msc_p < 0)
		st.msc_p = 4;
	else if (st.msc_p > 4)
		st.msc_p = 0;
	st = charge_msc(st);
	system("killall afplay");
	st.msc = 0;
	ft_music(st);
}

t_mlx	charge_msc(t_mlx st)
{
	if (st.msc_p == 0)
		st.msc_arg = ft_strdup("./music/raka_taka.mp3 &");
	else if (st.msc_p == 1)
		st.msc_arg = ft_strdup("./music/Dub.mp3 &");
	else if (st.msc_p == 2)
		st.msc_arg = ft_strdup("./music/Nada.mp3 &");
	else if (st.msc_p == 3)
		st.msc_arg = ft_strdup("./music/Comac.mp3 &");
	else if (st.msc_p == 4)
		st.msc_arg = ft_strdup("./music/Die.mp3 &");
	return (st);
}
