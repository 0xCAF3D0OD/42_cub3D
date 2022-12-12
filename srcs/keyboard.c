/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:18 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/14 15:16:07 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	key_down(int key, t_data *a)
{
	if (key == 13)
		a->keys.w = 1;
	if (key == 1)
		a->keys.s = 1;
	if (key == 0)
		a->keys.a = 1;
	if (key == 2)
		a->keys.d = 1;
	if (key == 123)
		a->keys.left = 1;
	if (key == 124)
		a->keys.right = 1;
	return (0);
}

int	key_up(int key, t_data *a)
{
	if (key == 13)
		a->keys.w = 0;
	if (key == 1)
		a->keys.s = 0;
	if (key == 0)
		a->keys.a = 0;
	if (key == 2)
		a->keys.d = 0;
	if (key == 123)
		a->keys.left = 0;
	if (key == 124)
		a->keys.right = 0;
	if (key == 53)
		exit_all(a);
	return (0);
}
