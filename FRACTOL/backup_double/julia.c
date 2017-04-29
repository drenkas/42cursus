/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:50:26 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/12 18:50:27 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_mlx   julia(t_mlx st)
{
    st.zoom = st.zoom_s + st.zoom_tmp;
    st.x = 0;
    
    if (st.check == 0)
    {
        st.x1 = -1.55 + st.x1_s;
        st.y1 = -1.55 + st.y1_s;
        st.cr = 0.13;
        st.ci = 0.68;
    }
    else
    {
        st.x1 = st.x1_s - (st.im_weidth / st.zoom) / 2;
        st.y1 = st.y1_s - (st.im_hight / st.zoom) / 2;
    }
    return (st);
}

t_mlx   init_julia(t_mlx st)
{
    st = julia(st);
    while(st.x < st.im_weidth)
    {
        st.y = 0;
        while (st.y <st.im_hight)
        {
            st.i = 0;
            st.zr = (st.x / st.zoom + st.x1);
            st.zi = (st.y / st.zoom + st.y1);
            while(st.zr * st.zr + st.zi * st.zi < 4 && st.i < st.iter)
            {
                st.tmp = st.zr;
				st.zr = st.zr * st.zr - st.zi * st.zi + st.cr;
				st.zi = 2 * st.zi * st.tmp + st.ci;
				st.i++;
            }
            change_draw(st);
            st.y++;
        }
        st.x++;
    }
    return (st);
}