/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:18:21 by gsilva            #+#    #+#             */
/*   Updated: 2023/02/07 21:12:07 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*map(void)
{
	static t_map	map_struct;

	return (&map_struct);
}

void	create_map(char *path)
{
	int	i;
	int	fd;

	fd = open(path, O_RDONLY);
	i = get_lines(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	map()->map = (char **)malloc((i + 1) * (sizeof(char *)));
	game()->map_lines = i;
	i = 0;
	while (1)
	{
		map()->map[i] = get_next_line(fd);
		if (!map()->map[i])
			break ;
		i++;
	}
	map()->map[i] = 0;
	map()->c = 0;
	map()->e = 0;
	map()->p = 0;
}

int	get_lines(int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
		i++;
	}
	return (i);
}
