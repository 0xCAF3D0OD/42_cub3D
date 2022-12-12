/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:37:54 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/21 22:53:38 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	manage_args(t_data *a, int ac, char **av)
{
	int	len;

	if (ac != 2)
		quit(a, "Please enter a map as an argument !");
	if (!av[1])
		quit(a, "Error: argument is NULL");
	len = ft_strlen(av[1]);
	if (ft_strncmp(av[1] + len - 4, ".cub", 4))
		quit(a, "Error: map must be in '.cub'");
}

void	print_right_line(char *line, int y, int x)
{
	int	i;

	i = -1;
	printf("\n%sThere is an error on line:	%d%s\n\n",
		COL_RED, y, COL_RES);
	if (x != 0)
	{
		while (++i <= (int)ft_strlen(line))
		{
			if (i == x)
				printf("%s'%c' => '%c'%s ", COL_RED, line[i - 1],
					line[i], COL_RES);
		}
		printf("\n");
	}
	else
	{
		while (++i <= (int)ft_strlen(line))
		{
			if (i == x)
				printf("%s'%c' <= '%c'%s", COL_RED, line[i - 1],
					line[i], COL_RES);
		}
		printf("\n");
	}
}

int	manage_map_error(char *line, int y, int x, int err)
{
	if (err == 0)
		printf("\n%s'no player in the map'%s\n\n", COL_RED, COL_RES);
	if (err == 4)
		printf("\n%s'to much player in the map'%s\n\n", COL_RED, COL_RES);
	if (err == 1)
		print_right_line(line, y, x);
	if (err == 2)
		print_right_line(line, y, x);
	if (err == 3)
		print_right_line(line, y, x);
	return (1);
}
