/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/30 15:48:40 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_chr	*chr(void)
{
	static t_chr	chr_struct;

	return (&chr_struct);
}

t_image	*img(void)
{
	static t_image	img_struct;

	return (&img_struct);
}

void	create_img(void)
{
	img()->width = 60;
	img()->height = 60;
	(chr()->img) = mlx_xpm_file_to_image(game()->mlx, "./assets/chr.xpm",
			&img()->width, &img()->height);
	(img()->wall) = mlx_xpm_file_to_image(game()->mlx, "./assets/wall.xpm",
			&img()->width, &img()->height);
	(img()->floor) = mlx_xpm_file_to_image(game()->mlx, "./assets/floor.xpm",
			&img()->width, &img()->height);
	(img()->colec) = mlx_xpm_file_to_image(game()->mlx, "./assets/colec.xpm",
			&img()->width, &img()->height);
	(img()->exit) = mlx_xpm_file_to_image(game()->mlx, "./assets/exit.xpm",
			&img()->width, &img()->height);
}
