/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:18:21 by gsilva            #+#    #+#             */
/*   Updated: 2023/01/25 14:15:52 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*map(void)
{
	static t_map	map_struct;

	return (&map_struct);
}

void	create_map(int fd)
{
	t_map	*tmp_node;
	char	*tmp;
	int		i;

	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp_node = new_map_node(tmp, i++);
		add_node(map(), tmp_node);
		i++;
	}
	game()->map_lines = i;
}

t_map	*new_map_node(char *content, int idx)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (0);
	new->line = content;
	new->index = idx;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_node(t_map *map, t_map *new)
{
	t_map	*tmp;

	if (!map->line)
	{
		map->line = new->line;
		map->index = new->index;
		map->next = new->next;
		map->prev = new->next;
		return ;
	}
	tmp = map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
