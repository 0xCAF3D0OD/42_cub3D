/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:07:30 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 22:22:13 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == '0')
			{
				if (x == 0 || x == (map->x - 1) || y == 0 || y == (map->y - 1))
					return (manage_map_error(map->map[y], y + 1, x, 1));
				if (map->map[y][x - 1] == ' ' || map->map[y][x + 1] == ' ')
					return (manage_map_error(map->map[y], y + 1, x, 2));
				if (map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' ')
					return (manage_map_error(map->map[y + 1], y + 1, x, 3));
			}
			++x;
		}
		++y;
	}
	return (0);
}

int	parse_map(char **lines, t_cam *cam, t_map *map)
{
	if (parse_map_size(lines, map))
		return (1);
	if (create_map(map))
		return (1);
	if (fill_map(lines, map, cam))
		return (1);
	if (check_map(map))
		return (1);
	return (0);
}
