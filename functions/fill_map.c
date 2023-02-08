/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:08:57 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/08 01:57:14 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_map(void)
{
	void	*floor;
	void	*wall;
	int		y;
	int		x;
	int		size;

	y = -1;
	size = 40;
	floor = mlx_xpm_file_to_image(game()->mlx, "./assets/floor.xpm",
			&size, &size);
	wall = mlx_xpm_file_to_image(game()->mlx, "./assets/wall.xpm",
			&size, &size);
	while (map()->map[++y])
	{
		x = -1;
		while (map()->map[y][++x])
		{
			mlx_put_image_to_window(game()->mlx, game()->win,
				floor, x * 40, y * 40);
			if (map()->map[y][x] == '1')
			{
				mlx_put_image_to_window(game()->mlx, game()->win,
					wall, x * 40, y * 40);
			}
		}
	}
}
