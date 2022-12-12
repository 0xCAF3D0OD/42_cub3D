/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:41 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:01 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_from_texture(t_img *i, int x, int y)
{
	char	*p;

	if (x < 0 || i->x <= x || y < 0 || i->y < y)
		return (0);
	p = i->addr + (y * i->ll + x * (i->bpp / 8));
	return (*(unsigned int *)p & 0x00FFFFFF);
}

void	draw_ceiling(t_data *a, t_ray *r, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i < r->offset)
	{
		j = 0;
		while (j++ < COLUMN_SIZE)
			put_pixel(&a->fp, j - 1 + index * COLUMN_SIZE, i, a->map.ceiling);
		i++;
	}
}

void	draw_column(t_data *a, t_ray *r, int index, t_img *img)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < r->size)
	{
		j = 0;
		color = get_color_from_texture(img, r->tx, r->ty);
		while (j++ < COLUMN_SIZE)
			put_pixel(&a->fp, j - 1 + index * COLUMN_SIZE,
				i + r->offset, color);
		i++;
		r->ty += r->step;
	}
}

void	draw_floor(t_data *a, t_ray *r, int index)
{
	int	i;
	int	j;

	i = r->offset + r->size;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j++ < COLUMN_SIZE)
			put_pixel(&a->fp, j - 1 + index * COLUMN_SIZE, i, a->map.floor);
		i++;
	}
}
