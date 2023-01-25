/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:10:30 by gsilva            #+#    #+#             */
/*   Updated: 2023/01/25 16:44:20 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(void)
{
	t_map	*tmp_map;
	int		i;

	tmp_map = map();
	i = 0;
	if (top_bot_check(tmp_map->line))
		return (0);
	tmp_map = tmp_map->next;
	while (tmp_map->next)
	{
		if (mid_check(tmp_map->line))
			return (0);
		tmp_map = tmp_map->next;
	}
	if (top_bot_check(tmp_map->line))
		return (0);
	return (1);
}

int	top_bot_check(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		obj_check(line[i]);
		if (line[i] != '1')
			return (1);
	}
	return (0);
}

int	mid_check(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (1);
	while (line[++i])
		obj_check(line[i]);
	if (line[i - 1] != '1')
		return (1);
	return (0);
}

void	obj_check(char c)
{
	if (c == 'P')
		game()->p += 1;
	else if (c == 'C')
		game()->c += 1;
	else if (c == 'E')
		game()->e += 1;
}
