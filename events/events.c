/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/09 15:36:56 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	walk_right(void);
static void	walk_left(void);
static void	walk_up(void);
static void	walk_down(void);

int	keyhook(int keycode)
{
	if (keycode)
	{
		if (keycode == 65363)
			walk_right();
		else if (keycode == 65361)
			walk_left();
		else if (keycode == 65362)
			walk_up();
		else if (keycode == 65364)
			walk_down();
		else if (keycode == 65307)
		{
			mlx_destroy_window(game()->mlx, game()->win);
			exit(0);
		}
		fill_map();
	}
	return (0);
}

static void	walk_right(void)
{
	if (map()->map[chr()->x][(chr()->y) + 1] != '1')
		chr()->y += 1;
}

static void	walk_left(void)
{
	if (map()->map[chr()->x][(chr()->y) - 1] != '1')
		chr()->y -= 1;
}

static void	walk_up(void)
{
	if (map()->map[(chr()->x) - 1][chr()->y] != '1')
		chr()->x -= 1;
}

static void	walk_down(void)
{
	if (map()->map[(chr()->x) + 1][chr()->y] != '1')
		chr()->x += 1;
}
