/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:12 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/22 14:06:45 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	free_tab(t_data *a)
//{
//	int	i;
//
//	i = 0;
//	while (a->map.map[i] != NULL)
//	{
//		if (a->map.map[i] != NULL)
//			free(a->map.map[i]);
//		a->map.map[i] = NULL;
//		i++;
//	}
//	if (a->map.map != NULL)
//		free(a->map.map);
//}
//
//void	free_input(t_data *a)
//{
//	int	i;
//
//	i = 0;
//	while (a->map.map[i] != NULL)
//	{
//		if (a->map.map[i] != NULL)
//			free(a->map.map[i]);
//		a->map.map[i] = NULL;
//		i++;
//	}
//	if (a->map.map != NULL)
//		free(a->map.map);
//}

void	free_map(t_data *a)
{
	int	i;

	i = 0;
	while (a->map.map[i] != NULL)
	{
		if (a->map.map[i] != NULL)
			free(a->map.map[i]);
		a->map.map[i] = NULL;
		i++;
	}
	if (a->map.map != NULL)
		free(a->map.map);
}

void	destroy_mlx(t_data *a)
{
	if (a->mini.img)
		mlx_destroy_image(a->mlx, a->mini.img);
	if (a->fp.img)
		mlx_destroy_image(a->mlx, a->fp.img);
	if (a->n.img)
		mlx_destroy_image(a->mlx, a->n.img);
	if (a->s.img)
		mlx_destroy_image(a->mlx, a->s.img);
	if (a->w.img)
		mlx_destroy_image(a->mlx, a->w.img);
	if (a->e.img)
		mlx_destroy_image(a->mlx, a->e.img);
	if (a->win)
		mlx_destroy_window(a->mlx, a->win);
}

void	exit_all(t_data *a)
{
	if (a->map.map)
		free_map(a);
	if (a->mlx)
		destroy_mlx(a);
	exit(EXIT_SUCCESS);
}

int	red_cross(t_data *a)
{
	exit_all(a);
	return (0);
}
