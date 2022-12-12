/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:14:50 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 23:12:10 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	calculat_h(char **file_data)
{
	int	i;
	int	j;

	i = 0;
	while (file_data[i])
	{
		j = 0;
		while (file_data[i][j])
		{
			if (file_data[i][j] == '1' || file_data[i][j] == ' '
				|| file_data[i][j] == '0')
			{
				if (file_data[i][j + 1] == '\0')
					return (i);
				j++;
			}
			else
				break ;
		}
		++i;
	}
	return (0);
}

int	parse_map_size(char **lines, t_map *map)
{
	int	x_max;
	int	x_tmp;
	int	i;

	x_max = 0;
	i = 0;
	while (lines[i])
	{
		x_tmp = ft_strlen(lines[i]);
		if (x_max < x_tmp)
			x_max = x_tmp;
		++i;
	}
	if (x_max == 0 || i == 0)
		return (1);
	map->x = x_max;
	map->y = i;
	return (0);
}
