/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:24:53 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 17:24:53 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *chr, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (chr)
	{
		while (chr[i] != '\0' && f)
		{
			(*f)(i, &chr[i]);
			i++;
		}
	}
}
