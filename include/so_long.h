/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:10 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/08 17:29:18 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_chr
{
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	void	*img;
}	t_chr;

typedef struct s_map
{
	int		index;
	char	*line;
	void	*prev;
	void	*next;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		map_lines;
}	t_game;

int		keyhook(int keycode, t_chr *chr);

void	add_node(t_map *map, t_map *new);

void	create_map(int fd);

void	create_chr(void);

void	create_win(void);

t_map	*new_map_node(char *content, int idx);

t_game	*game(void);

t_map	*map(void);

t_chr	*chr(void);

#endif