/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:14 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/08 01:25:10 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{

	(void)argc;
	game()->mlx = mlx_init();
	create_map(argv[1]);
	if (!check_map())
	{
		ft_printf("Invalid map!\n");
		return (0);
	}
	create_win();
	create_chr();
	fill_map();
	mlx_put_image_to_window(game()->mlx, game()->win,
		chr()->img, chr()->y * 40, chr()->x * 40);
	mlx_key_hook(game()->win, keyhook, chr());
	mlx_loop(game()->mlx);
	return (0);
}
