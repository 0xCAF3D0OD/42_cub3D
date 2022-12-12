/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdi-noce <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:39:59 by kdi-noce          #+#    #+#             */
/*   Updated: 2022/11/22 13:44:05 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_the_rest_sprite(char *input)
{
	char	**new_array;
	int		args;
	int		i;

	args = 0;
	i = -1;
	new_array = ft_split(input, ' ');
	while (new_array[args])
		args++;
	while (new_array[++i])
		free(new_array[i]);
	return (args);
}

int	check_sprite(char *array, t_text *dirct, t_sprite *sprite)
{
	char	*tmp;

	if (ret_space(array, 1))
		return (0);
	tmp = check_space(array, 1);
	if (ft_strlen(tmp) < 14)
		return (0);
	if (array && !ft_isalpha(array[0]))
		array = check_space(array, 0);
	if (array && tmp && !ft_strncmp(array, "NO", 2))
		manage_path_dirct_s(sprite, dirct, tmp, 1);
	else if (array && tmp && !ft_strncmp(array, "SO", 2))
		manage_path_dirct_s(sprite, dirct, tmp, 2);
	else if (array && tmp && !ft_strncmp(array, "WE", 2))
		manage_path_dirct_s(sprite, dirct, tmp, 3);
	else if (array && tmp && !ft_strncmp(array, "EA", 2))
		manage_path_dirct_s(sprite, dirct, tmp, 4);
	if (dirct->no == 1 && dirct->so == 1 && dirct->we == 1 && dirct->ea == 1)
		return (4);
	return (0);
}
//printf("NO=%d	SO=%d	WE=%d	EA=%d\n",
// dirct->no, dirct->so, dirct->we, dirct->ea);

int	parse_sprite(t_data *a, t_args *input, t_sprite *sprite)
{
	int static	idx_text;
	t_text		dirct;

	input->y = 0;
	idx_text = 0;
	struct_init(&dirct);
	while (input->y < calculat_h(a->file_data))
	{
		idx_text += check_sprite(input->input[input->y], &dirct, sprite);
		if (input->input[input->y + 1] && idx_text == 4)
		{
			if ((check_the_rest_sprite(input->input[input->y]) == 2))
				break ;
		}
		input->y++;
	}
	if (idx_text != 4)
		return (1);
	return (0);
}
//		printf("%s\n", input->input[input->y]);
