/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublearrsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:39:07 by drenkas           #+#    #+#             */
/*   Updated: 2017/02/26 19:39:07 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_doublearrsize(char **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		check_line(str[i]);
		i++;
	}
	return (i);
}

void	check_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
		{
			if (line[i] == ',')
			{
				if (ch_after_nul(line, i) == 0)
					exit(1);
				else
					break ;
			}
			else
				exit(1);
		}
		i++;
	}
}

int		ch_after_nul(char *elem, int i)
{
	int n;

	n = 0;
	if (elem[i + 1] == '0' && elem[i + 2] == 'x')
	{
		i += 3;
		while (elem[i] != '\0')
		{
			n++;
			i++;
		}
		if (n != 6)
			return (0);
		else
			return (1);
	}
	if ((elem[i + 1] >= '0' && elem[i + 1] <= '9') || elem[i + 1] == '\0')
		return (1);
	else
		return (0);
}
