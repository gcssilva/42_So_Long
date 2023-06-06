/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:14 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/31 16:43:50 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	game()->mlx = mlx_init();
	game()->moves = 0;
	create_map(argv[1]);
	if (!map()->map || argc != 2 || !check_map())
	{
		ft_printf("Error\nInvalid map!\n");
		return (0);
	}
	create_img();
	create_win();
	fill_map();
	mlx_hook(game()->win, 2, 1L << 0, keyhook, game()->mlx);
	mlx_hook(game()->win, 17, 1L << 0, close_win, game()->mlx);
	mlx_loop(game()->mlx);
	return (0);
}
