/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:03:53 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/14 16:04:16 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_img(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->y)
	{
		j = 0;
		while (j++ < img->x)
			put_pixel(img, j, i, 0x0);
		i++;
	}
}

void	render_frame(t_data *a)
{
	clear_img(&a->mini);
	clear_img(&a->fp);
	draw_map(a);
	draw_cam(a);
	raycasting(a);
	mlx_put_image_to_window(a->mlx, a->win, a->fp.img, 0, 0);
	mlx_put_image_to_window(a->mlx, a->win, a->mini.img, 50, 50);
}

int	loop_render(t_data *a)
{
	if (a->keys.w)
		move(a, 1);
	else if (a->keys.s)
		move(a, -1);
	if (a->keys.a)
		rl_move(a, -1);
	else if (a->keys.d)
		rl_move(a, 1);
	if (a->keys.left)
		rotate(a, -0.02);
	if (a->keys.right)
		rotate(a, 0.02);
	render_frame(a);
	return (0);
}
