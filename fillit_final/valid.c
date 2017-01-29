/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:38:14 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/17 16:38:14 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static	char	*ft_flood(int i, char *str)
{
	if (str[i + 1] == '#')
	{
		str[i + 1] = 'x';
		str = ft_flood(i + 1, str);
	}
	if (str[i - 1] >= 0 && str[i - 1] == '#')
	{
		str[i - 1] = 'x';
		str = ft_flood(i - 1, str);
	}
	if (i + 5 <= 20 && str[i + 5] == '#')
	{
		str[i + 5] = 'x';
		str = ft_flood(i + 5, str);
	}
	return (str);
}

void			ft_ultcheck(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] && str[i] != '#')
		i++;
	str[i] = 'x';
	str = ft_flood(i, str);
	while (*str)
	{
		if (*str == 'x')
		{
			*str = '#';
			res++;
		}
		str++;
	}
	if (res != 4)
		ft_error();
}

static	void	ft_linecheck(char *read_b)
{
	int i;
	int n;
	int j;

	i = 0;
	n = 0;
	j = 0;
	while (read_b[i] != '\0')
	{
		if (read_b[i] == '\n')
		{
			n++;
			j = n % 4;
			if (read_b[i + 1] == '\n' && j == 0)
			{
				n = 0;
				i++;
			}
			else if (read_b[i + 1] == '\n')
				ft_error();
		}
		i++;
	}
}

int				ft_early_valid(char *read_b)
{
	int dot;
	int sharp;
	int end;

	dot = 0;
	sharp = 0;
	end = 0;
	ft_linecheck(read_b);
	while (*read_b)
	{
		if (*read_b == '.')
			dot++;
		else if (*read_b == '#')
			sharp++;
		else if (*read_b == '\n')
			end++;
		else
			ft_error();
		read_b++;
	}
	if (sharp < 4)
		ft_error();
	if (dot % 4 || sharp % 4 || (end + 1) % 5)
		ft_error();
	return (sharp / 4);
}

int				ft_max_size(t_block *block)
{
	int i;
	int max;

	i = 0;
	max = 2;
	while (block->next && i++)
		block = block->next;
	while (max < i * i)
		max++;
	return (max);
}
