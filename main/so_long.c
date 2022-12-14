/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:14 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/08 16:59:16 by gsilva           ###   ########.fr       */
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
	mlx_hook(game()->win, 2, 1L << 0, keyhook, chr());
	mlx_loop(game()->mlx);
	return (0);
}
