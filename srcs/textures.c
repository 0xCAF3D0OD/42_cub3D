/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:43 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/23 15:54:14 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tile(t_img *img, char *file, void *mlx)
{
	img->img = mlx_xpm_file_to_image(mlx, file, &img->x, &img->y);
}

void	init_textures(t_data *a)
{
	init_tile(&a->n, a->sprite.no, a->mlx);
	init_tile(&a->s, a->sprite.so, a->mlx);
	init_tile(&a->e, a->sprite.ea, a->mlx);
	init_tile(&a->w, a->sprite.we, a->mlx);
	if (!a->n.img || !a->s.img || !a->e.img || !a->w.img)
		quit(a, "Error: texture not found");
	a->n.addr = mlx_get_data_addr(a->n.img, &a->n.bpp, &a->n.ll, &a->n.endian);
	a->s.addr = mlx_get_data_addr(a->s.img, &a->s.bpp, &a->s.ll, &a->s.endian);
	a->e.addr = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.ll, &a->e.endian);
	a->w.addr = mlx_get_data_addr(a->w.img, &a->w.bpp, &a->w.ll, &a->w.endian);
}
