/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:25 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/21 17:46:46 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int	check_wall(t_data *a, float x, float y)
{
	int	mx;
	int	my;

	mx = ((int)x) >> 6;
	my = ((int)y) >> 6;
	if (0 <= mx && mx < a->map.x && 0 <= my && my < a->map.y
		&& a->map.map[my][mx] == '0')
		return (1);
	return (0);
}

int	check_move(t_data *a, int x, int y)
{
	int	off;

	off = 20.0;
	if (check_wall(a, x + off, y + off) && check_wall(a, x + off, y - off)
		&& check_wall(a, x - off, y + off) && check_wall(a, x - off, y - off))
		return (1);
	return (0);
}

void	move(t_data *a, int dir)
{
	float	new_x;
	float	new_y;

	new_x = a->cam.x + a->cam.dx * dir * 5.0;
	new_y = a->cam.y + a->cam.dy * dir * 5.0;
	if (check_move(a, new_x, a->cam.y))
		a->cam.x = new_x;
	if (check_move(a, a->cam.x, new_y))
		a->cam.y = new_y;
}

void	rl_move(t_data *a, int dir)
{
	float	dx;
	float	dy;
	float	new_x;
	float	new_y;

	dx = cos(add_rad(a->cam.a, PI / 2));
	dy = sin(add_rad(a->cam.a, PI / 2));
	new_x = a->cam.x + dx * dir * 5.0;
	new_y = a->cam.y + dy * dir * 5.0;
	if (check_move(a, new_x, a->cam.y))
		a->cam.x = new_x;
	if (check_move(a, a->cam.x, new_y))
		a->cam.y = new_y;
}

void	rotate(t_data *a, double da)
{
	a->cam.a = add_rad(a->cam.a, da);
	a->cam.dx = cos(a->cam.a);
	a->cam.dy = sin(a->cam.a);
}
