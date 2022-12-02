/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:14 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/02 16:55:38 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	t_map_info	*map;
	int			map_file;

	if (argc > 0)
	{
		map_file = open(argv[1], O_RDONLY);
		map = create_map(map_file);
		game = (t_game *)malloc(sizeof(t_game));
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx,
				map->width * 40, map->height * 40, "so_long");
		game->img = mlx_xpm_file_to_image(game->mlx,
				"./assets/pixil-frame-0.xpm",
				&game->img_width, &game->img_height);
		mlx_key_hook(game->win, keyhook, &game);
		mlx_loop(game->mlx);
	}
	return (0);
}
