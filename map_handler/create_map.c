/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:18:21 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/02 16:50:09 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map_info	*create_map(int fd)
{
	t_map_info	*map_info;
	t_map		*node;
	t_map		*tmp_node;
	char		*tmp;
	int			i;

	node = 0;
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp_node = new_map_node(tmp, i++);
		add_node(&node, tmp_node);
	}
	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!map_info)
		return (0);
	map_info->first = node;
	map_info->last = tmp_node;
	map_info->width = ft_strlen(tmp);
	map_info->height = i - 1;
	return (map_info);
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

void	add_node(t_map **map, t_map *new)
{
	t_map	*tmp;

	if (!*map)
	{
		*map = new;
		return ;
	}
	tmp = *map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
