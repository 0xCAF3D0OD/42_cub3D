/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:13:25 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 15:22:37 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	check_path(char *array)
{
	int	tmp;

	if (array)
	{
		tmp = open(array, O_RDONLY);
		if (tmp <= 0)
			return (0);
		close(tmp);
	}
	return (1);
}

int	check_path_s(t_sprite *sprite, char *str, int ret)
{
	if (!str)
		return (1);
	if (ret == 1)
		sprite->no = str;
	if (ret == 2)
		sprite->so = str;
	if (ret == 3)
		sprite->we = str;
	if (ret == 4)
		sprite->ea = str;
	return (0);
}
//	if (!check_path(str))
//		return (1);

int	manage_path_dirct_s(t_sprite *sprite, t_text *dirct, char *str, int ret)
{
	if (check_path_s(sprite, str, ret))
		return (1);
	if (ret == 1)
		dirct->no++;
	if (ret == 2)
		dirct->so++;
	if (ret == 3)
		dirct->we++;
	if (ret == 4)
		dirct->ea++;
	return (0);
}
//	printf("S %d\n", check_path_s(sprite, str, ret));
