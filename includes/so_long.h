/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:10 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/02 16:57:38 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	int		pos_y;
	int		pos_x;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
}	t_game;

typedef struct s_map
{
	int		index;
	char	*line;
	void	*prev;
	void	*next;
}	t_map;

typedef struct s_map_info
{
	int		width;
	int		height;
	t_map	*first;
	t_map	*last;
}	t_map_info;


int			keyhook(int keycode, t_game *game);

void		add_node(t_map **map, t_map *new);

t_map_info	*create_map(int fd);

t_map		*new_map_node(char *content, int idx);

#endif