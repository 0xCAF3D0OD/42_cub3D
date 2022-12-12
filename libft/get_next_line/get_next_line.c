/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:35:49 by amuhleth          #+#    #+#             */
/*   Updated: 2021/12/29 19:18:00 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete_str(char **str)
{
	free(*str);
	*str = NULL;
}

char	*split_result(char **str)
{
	char	*result;
	char	*tmp;
	int		result_len;

	result_len = 0;
	while ((*str)[result_len] != '\n' && (*str)[result_len])
		result_len++;
	if ((*str)[result_len] == '\n')
	{
		result = (char *) malloc(sizeof(char) * (result_len + 2));
		ft_strlcpy(result, *str, result_len + 2);
		result[result_len + 1] = '\0';
		tmp = ft_strdup(*str + result_len + 1);
		free(*str);
		*str = tmp;
	}
	else
	{
		result = ft_strdup(*str);
		delete_str(str);
	}
	return (result);
}

void	fill_str(char **str, char *buffer)
{
	char	*tmp;

	if (*str == NULL)
		*str = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(*str, buffer);
		free(*str);
		*str = tmp;
	}
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	static char	*str;
	char		*result;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (ft_strchr(str, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		fill_str(&str, buffer);
		if (bytes_read == 0)
			break ;
	}
	if (*str == '\0')
	{
		delete_str(&str);
		return (NULL);
	}
	result = split_result(&str);
	return (result);
}
