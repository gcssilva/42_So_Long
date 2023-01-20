/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/01/20 12:57:19 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	find_chr(t_chr *chr);

t_chr	*chr(void)
{
	static t_chr	chr_struct;

	return (&chr_struct);
}

void	create_chr(void)
{
	chr()->width = 40;
	chr()->height = 40;
	chr()->img = mlx_xpm_file_to_image(game()->mlx, "../assets/chr.xpm", &chr()->width, &chr()->height);
	find_chr(chr());
}

static void	find_chr(t_chr *chr)
{
	t_map	*tmp;
	int		i;

	tmp = map();
	while (tmp)
	{
		i = 0;
		while (tmp->line[i] && tmp->line[i] != 'P')
			i++;
		if (tmp->line[i] == 'P')
		{
			chr->pos_y = tmp->index;
			chr->pos_x = i;
		}
		tmp = tmp->next;
	}
}
