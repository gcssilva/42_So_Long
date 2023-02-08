/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:58:14 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/07 22:38:04 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_win(void)
{
	int		x;
	void	*tmp;

	x = ft_strlen(map()->map[0]) - 1;
	tmp = mlx_new_window(game()->mlx, x * 40,
			game()->map_lines * 40, "so_long");
	game()->win = tmp;
}
