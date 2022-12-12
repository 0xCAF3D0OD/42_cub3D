/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:56 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/14 15:23:32 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(t_data *a, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->map.size)
	{
		j = 0;
		while (j++ < a->map.size)
			put_pixel(&a->mini, x + j - 1, y + i, 0x808080);
		i++;
	}
	i = 1;
	while (i < a->map.size - 1)
	{
		j = 1;
		while (j++ < a->map.size - 1)
			put_pixel(&a->mini, x + j - 1, y + i, color);
		i++;
	}
}

void	draw_map(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map.map[i] != NULL)
	{
		j = 0;
		while (a->map.map[i][j] != '\0')
		{
			if (a->map.map[i][j] == '1')
			{
				draw_tile(a, j * a->map.size, i * a->map.size, 0x22FFFFFF);
			}
			if (a->map.map[i][j] == '0')
			{
				draw_tile(a, j * a->map.size, i * a->map.size, 0x99000000);
			}
			j++;
		}
		i++;
	}
}

void	draw_cam(t_data *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->cam.size)
	{
		j = 0;
		while (j++ < a->cam.size)
			put_pixel(&a->mini, j - 1 + a->cam.x / 64 * a->map.size,
				i + a->cam.y / 64 * a->map.size, a->cam.color);
		i++;
	}
	i = 0;
	while (i < a->cam.size - 2)
	{
		j = 0;
		while (j < a->cam.size - 2)
		{
			put_pixel(&a->mini, j + a->cam.x / 64 * a->map.size + a->cam.dx * 5,
				i + a->cam.y / 64 * a->map.size + a->cam.dy * 5, a->cam.color);
			j++;
		}
		i++;
	}
}
