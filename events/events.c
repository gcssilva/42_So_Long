/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/01/25 16:59:30 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	keyhook(int keycode)
{
	if (keycode)
	{
		if (keycode == 65363)
			chr()->pos_y += 1;
		else if (keycode == 65361)
			chr()->pos_y -= 1;
		else if (keycode == 65364)
			chr()->pos_x += 1;
		else if (keycode == 65362)
			chr()->pos_x -= 1;
		else if (keycode == 65307)
		{
			mlx_destroy_window(game()->mlx, game()->win);
			exit(0);
		}
		mlx_clear_window(game()->mlx, game()->win);
		mlx_put_image_to_window(game()->mlx, game()->win,
			chr()->img, chr()->pos_y * 40, chr()->pos_x * 40);
	}
	return (0);
}
