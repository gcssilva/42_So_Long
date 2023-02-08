/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:10 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/08 01:10:31 by gsilva           ###   ########.fr       */
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
	int		y;
	int		x;
	int		width;
	int		height;
	void	*img;
}	t_chr;

typedef struct s_map
{
	char	**map;
	int		c;
	int		e;
	int		p;
}	t_map;

typedef struct s_game
{
	int		map_lines;
	void	*mlx;
	void	*win;
}	t_game;

int		check_map(void);

int		keyhook(int keycode);

int		top_bot_check(char *line);

int		mid_check(char *line, int x);

int		get_lines(int fd);

void	fill_map(void);

void	path_check(int y, int x);

void	obj_check(char c, int y, int x);

void	create_map(char *path);

void	create_chr(void);

void	create_win(void);

t_game	*game(void);

t_map	*map(void);

t_chr	*chr(void);

#endif