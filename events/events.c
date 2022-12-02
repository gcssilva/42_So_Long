/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:39 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/02 16:11:29 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keyhook(int keycode, t_game *game)
{
	if (keycode)
	{
		if (keycode == 65363)
			game->pos_y += 40;
		else if (keycode == 65361)
			game->pos_y -= 40;
		else if (keycode == 65364)
			game->pos_x += 40;
		else if (keycode == 65362)
			game->pos_x -= 40;
		else if (keycode == 65307)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img, game->pos_y, game->pos_x);
	}
	return (0);
}
