/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:08:57 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/09 15:36:39 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_map(void)
{
	int		y;
	int		x;

	y = -1;
	while (map()->map[++y])
	{
		x = -1;
		while (map()->map[y][++x])
		{
			mlx_put_image_to_window(game()->mlx, game()->win,
				img()->floor, x * 60, y * 60);
			if (map()->map[y][x] == '1')
			{
				mlx_put_image_to_window(game()->mlx, game()->win,
					img()->wall, x * 60, y * 60);
			}
		}
	}
	mlx_put_image_to_window(game()->mlx, game()->win,
		chr()->img, chr()->y * 60, chr()->x * 60);
}
