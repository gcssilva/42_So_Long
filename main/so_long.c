/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:14 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/06 15:42:57 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{

	(void)argc;
	game()->mlx = mlx_init();
	create_map(argv[1]);
	if (!check_map)
		return ;
	create_win();
	create_chr();
	mlx_key_hook(game()->win, keyhook, chr());
	mlx_put_image_to_window(game()->mlx, game()->win,
		chr()->img, chr()->pos_y * 40, chr()->pos_x * 40);
	mlx_loop(game()->mlx);
	return (0);
}
