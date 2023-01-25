/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:14 by gsilva            #+#    #+#             */
/*   Updated: 2023/01/25 17:08:36 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		map_file;

	(void)argc;
	game()->mlx = mlx_init();
	map_file = open(argv[1], O_RDONLY);
	create_map(map_file);
	create_win();
	create_chr();
	mlx_key_hook(game()->win, keyhook, chr());
	mlx_put_image_to_window(game()->mlx, game()->win,
		chr()->img, chr()->pos_y * 40, chr()->pos_x * 40);
	mlx_loop(game()->mlx);
	return (0);
}
