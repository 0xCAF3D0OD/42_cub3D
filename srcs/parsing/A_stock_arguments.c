/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:16:13 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/21 22:51:28 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parse_input_size(char **file_data, t_args *input)
{
	int	x_max;
	int	x_tmp;
	int	i;

	x_max = 0;
	i = 0;
	while (i <= calculat_h(file_data))
	{
		x_tmp = ft_strlen(file_data[i]);
		if (x_max < x_tmp)
			x_max = x_tmp;
		++i;
	}
	if (x_max == 0 || i == 0)
		return (1);
	input->x = x_max;
	input->y = i;
	return (0);
}

void	reset_input(t_args *input)
{
	int	x;
	int	y;

	y = 0;
	while (y < input->y)
	{
		x = 0;
		while (x < input->x)
		{
			input->input[y][x] = 0;
			++x;
		}
		++y;
	}
}

int	create_input(t_args *input)
{
	int		i;

	input->input = ft_calloc(sizeof(char *), input->y + 1);
	if (input->input == NULL)
		return (1);
	input->input[input->y] = NULL;
	i = 0;
	while (i < input->y)
	{
		input->input[i] = ft_calloc(sizeof(char), input->x + 1);
		if (input->input[i] == NULL)
		{
			while (i--)
				free(input->input[i]);
			free(input->input);
			return (1);
		}
		input->input[i][input->x] = '\0';
		++i;
	}
	reset_input(input);
	return (0);
}

void	fill_input(char **file_data, t_args *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < input->y)
	{
		j = 0;
		while (file_data[i][j])
		{
			input->input[i][j] = file_data[i][j];
			j++;
		}
		++i;
	}
}

int	parse_arguments(t_data *a, t_args *input)
{
	if (parse_input_size(a->file_data, input))
		quit(a, "Error: invalid map, size null");
	if (create_input(input))
		quit(a, "Error: failed to create map array");
	fill_input(a->file_data, input);
	return (0);
}
