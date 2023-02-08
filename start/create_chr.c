/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/07 22:12:59 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_chr	*chr(void)
{
	static t_chr	chr_struct;

	return (&chr_struct);
}

void	create_chr(void)
{
	void	*tmp;

	chr()->width = 40;
	chr()->height = 40;
	tmp = mlx_xpm_file_to_image(game()->mlx, "./assets/chr.xpm", &chr()->width,
			&chr()->height);
	chr()->img = tmp;
}
