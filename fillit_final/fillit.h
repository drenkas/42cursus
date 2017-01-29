/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:35:37 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/17 16:35:38 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_block
{
	char			c;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_block	*next;
}					t_block;

char				*ft_read(char *file);
void				ft_error(void);
t_block				*ft_update_coord(t_block *block, int x, int y);
t_block				*ft_default_coord(t_block *block);
t_block				*ft_store(char *str);
char				**ft_fill(char **blk, int max);
int					ft_max_size(t_block *block);
char				**ft_solve(char **blk, t_block *block, int max);
char				**ft_res(t_block *block, int max);
void				ft_ultcheck (char *str);
int					ft_early_valid(char *read_b);
#endif
