/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_tools_fct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:53:07 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/22 23:53:09 by kdi-noce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	count_idx(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	go_on(char *str, int ret)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && ret == 1)
			return (0);
		if (!ft_isalpha(str[i]) && ret == 2)
			return (0);
		if (!ft_isdigit(str[i]) && ret == 3)
			return (0);
		i++;
	}
	return (1);
}

int	check_point(char *str)
{
	int	x;
	int	point;

	x = 0;
	point = 0;
	while (str[x])
	{
		if (str[0] == 44)
			return (1);
		if ((x == (int)(ft_strlen(str) - 1)) && (str[x] == 44))
			return (1);
		if (str[x] == ',')
			point++;
		x++;
	}
	if (point != 2)
		return (1);
	return (0);
}
