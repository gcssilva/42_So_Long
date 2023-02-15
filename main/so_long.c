/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:14 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/15 15:25:39 by gsilva           ###   ########.fr       */
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
	create_img();
	fill_map();
	mlx_key_hook(game()->win, keyhook, chr());
	mlx_loop(game()->mlx);
	return (0);
}
