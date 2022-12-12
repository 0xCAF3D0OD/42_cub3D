/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:20:49 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/14 15:37:34 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	add_rad(float a1, float a2)
{
	a1 += a2;
	if (a1 < 0.0)
		a1 += 2 * PI;
	else if (a1 >= 2 * PI)
		a1 -= 2 * PI;
	return (a1);
}

void	put_pixel(t_img *i, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || i->x <= x || y < 0 || i->y <= y)
		return ;
	dst = i->addr + (y * i->ll + x * (i->bpp / 8));
	*(unsigned int *)dst = color;
}
