/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:10:30 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/07 16:34:39 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(void)
{
	int	i;

	i = 0;
	top_bot_check(map()->map[0]);
	while (map()->map[i + 1])
	{
		mid_check(map()->map[i]);
		if (chr()->pos_x)
			chr()->pos_y = i;
		i++;
	}
	top_bot_check(map()->map[i]);
	if (map()->c == 0 || map()->e != 1 || map()->p != 1)
		return (0);
	path_check(chr()->pos_y, chr()->pos_x);
	if (map()->c != 0 || map()->e != 0)
		return (0);
	i = -1;
	while (map()->map[++i])
		ft_printf("%s", map()->map[i]);
	ft_printf("\n%u %u\n", map()->c, map()->e);
	return (1);
}

int	top_bot_check(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			return (1);
	return (0);
}

int	mid_check(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (1);
	while (line[++i])
		obj_check(line[i], i);
	if (line[i - 1] != '1')
		return (1);
	return (0);
}

void	obj_check(char c, int i)
{
	if (c == 'P')
	{
		chr()->pos_x = i;
		map()->p += 1;
	}
	else if (c == 'C')
		map()->c += 1;
	else if (c == 'E')
		map()->e += 1;
}

void	path_check(int y, int x)
{
	if (!map()->map[y][x] || map()->map[y][x] == '1' || map()->map[y][x] == 'o'
		|| map()->map[y][x] == 'c' || map()->map[y][x] == 'e')
		return ;
	if (map()->map[y][x] == '0')
		map()->map[y][x] = 'o';
	else if (map()->map[y][x] == 'C')
	{
		map()->map[y][x] = 'c';
		map()->c -= 1;
	}
	else if (map()->map[y][x] == 'E')
	{
		map()->map[y][x] = 'e';
		map()->e -= 1;
	}
	path_check(y, x + 1);
	path_check(y + 1, x);
	path_check(y, x - 1);
	path_check(y - 1, x);
}
