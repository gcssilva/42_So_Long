/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:10:30 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/08 20:03:13 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(void)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map()->map[0]);
	if (!top_bot_check(map()->map[0]))
		return (0);
	while (map()->map[i + 1])
	{
		mid_check(map()->map[i], i);
		if (ft_strlen(map()->map[i]) != len)
			return (0);
		i++;
	}
	if (ft_strlen(map()->map[i]) != (len - 1)
		|| !top_bot_check(map()->map[i]))
		return (0);
	if (map()->c == 0 || map()->e != 1 || map()->p != 1)
		return (0);
	path_check(chr()->y, chr()->x);
	if (map()->c != 0 || map()->e != 0)
		return (0);
	return (1);
}

int	top_bot_check(char *line)
{
	int	i;

	i = -1;
	while (line[i] && line[i] != '\n')
		if (line[i] != '1')
			return (0);
	return (1);
}

int	mid_check(char *line, int x)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (1);
	while (line[++i])
		obj_check(line[i], i, x);
	if (line[i - 1] != '1')
		return (1);
	return (0);
}

void	obj_check(char c, int y, int x)
{
	if (c == 'P')
	{
		chr()->y = y;
		chr()->x = x;
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
		|| map()->map[y][x] == 'c' || map()->map[y][x] == 'e'
		|| map()->map[y][x] == 'p')
		return ;
	if (map()->map[y][x] == '0')
		map()->map[y][x] = 'o';
	else if (map()->map[y][x] == 'P')
	{
		map()->map[y][x] = 'p';
	}
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
