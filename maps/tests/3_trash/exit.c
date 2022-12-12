/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:12 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/09 16:38:14 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../cube/cub3d.h"
#include "../0_parser_maps.h"
/*int	i;

i = 0;
while (a->map.map[i] != NULL)
{
	if (a->map.map[i] != NULL)
		free(a->map.map[i]);
	a->map.map[i] = NULL;
	i++;
}*/
void	free_map(t_data *a)
{
	if (a->map.map != NULL)
		free(a->map.map);
}

void	exit_all(t_data *a)
{
	free_map(a);
	mlx_destroy_image(a->mlx, a->mini.img);
	mlx_destroy_image(a->mlx, a->fp.img);
	exit(EXIT_SUCCESS);
}

int	red_cross(t_data *a)
{
	(void)a;
	exit(0);
	return (0);
}
