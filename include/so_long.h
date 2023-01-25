/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:10 by gsilva            #+#    #+#             */
/*   Updated: 2023/01/25 16:57:44 by gsilva           ###   ########.fr       */
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
	int		c;
	int		e;
	int		p;
	int		map_lines;
}	t_game;

# define _CHR "./assets/chr.xpm"

int		check_map(void);

int		keyhook(int keycode);

int		top_bot_check(char *line);

int		mid_check(char *line);

void	obj_check(char c);

void	add_node(t_map *map, t_map *new);

void	create_map(int fd);

void	create_chr(void);

void	create_win(void);

t_map	*new_map_node(char *content, int idx);

t_game	*game(void);

t_map	*map(void);

t_chr	*chr(void);

#endif