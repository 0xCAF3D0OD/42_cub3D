/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:03:17 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/23 15:51:18 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	fix_fisheye(float dist, int i)
{
	float	angle;

	angle = add_rad(-(VIEW_FIELD / 2),
			i * VIEW_FIELD / (WIN_WIDTH / COLUMN_SIZE));
	return (dist * cos(angle));
}

void	set_column_data(t_img *img, t_ray *r, int i, int invert)
{
	r->dist = fix_fisheye(r->dist, i);
	r->size = 64 * WIN_HEIGHT / r->dist;
	r->step = img->y / r->size;
	r->tyoff = 0;
	if (r->size > WIN_HEIGHT)
	{
		r->tyoff = (r->size - WIN_HEIGHT) / 2;
		r->size = WIN_HEIGHT;
	}
	r->offset = WIN_HEIGHT / 2 - r->size / 2;
	r->ty = r->step * r->tyoff;
	r->tx = (int)(r->value / (64 / img->x)) % img->x;
	if (invert)
		r->tx = img->x - 1 - r->tx;
}

void	render_column(t_data *a, t_ray *r, t_img *img, int invert)
{
	set_column_data(img, r, r->i, invert);
	draw_ceiling(a, r, r->i);
	draw_column(a, r, r->i, img);
	draw_floor(a, r, r->i);
}
