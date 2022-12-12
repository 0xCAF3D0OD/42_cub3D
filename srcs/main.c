/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:17 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/23 15:55:52 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_graphics(t_data *a)
{
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	a->fp.x = WIN_WIDTH;
	a->fp.y = WIN_HEIGHT;
	a->fp.img = mlx_new_image(a->mlx, a->fp.x, a->fp.y);
	a->fp.addr = mlx_get_data_addr(a->fp.img, &a->fp.bpp, &a->fp.ll,
			&a->fp.endian);
	a->mini.x = a->map.x * a->map.size;
	a->mini.y = a->map.y * a->map.size;
	a->mini.img = mlx_new_image(a->mlx, a->mini.x, a->mini.y);
	a->mini.addr = mlx_get_data_addr(a->mini.img, &a->mini.bpp, &a->mini.ll,
			&a->mini.endian);
}

void	init_mlx_hooks(t_data *a)
{
	mlx_hook(a->win, ON_KEYDOWN, 0, &key_down, a);
	mlx_hook(a->win, ON_KEYUP, 0, &key_up, a);
	mlx_hook(a->win, ON_DESTROY, 0, &red_cross, a);
	mlx_loop_hook(a->mlx, &loop_render, a);
	mlx_loop(a->mlx);
}

void	set_dynamic_map(t_data *a)
{
	if (a->map.x <= 10 && a->map.y <= 16)
		a->map.size = 20;
	else if (a->map.x <= 20 && a->map.y <= 32)
		a->map.size = 10;
	else
		a->map.size = 5;
}

void	init_game(t_data *a)
{
	a->cam.dx = cos(a->cam.a);
	a->cam.dy = sin(a->cam.a);
	a->cam.size = 4;
	a->cam.color = 0xFFFF00;
	render_frame(a);
}

int	main(int argc, char **argv)
{
	t_data	a;

	ft_bzero(&a, sizeof(a));
	parser(argc, argv, &a);
	set_dynamic_map(&a);
	init_graphics(&a);
	init_textures(&a);
	init_game(&a);
	init_mlx_hooks(&a);
}
