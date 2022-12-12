/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:42 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/07 18:28:41 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

static int	ft_substrlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	count_strs(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		count++;
	}
	if (c != '\0')
	{
		if (s[i - 1] == c)
			count--;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		nb_strs;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_calloc(sizeof(char *), 1));
	nb_strs = count_strs(s, c);
	strs = (char **) ft_calloc(sizeof(char *), nb_strs + 1);
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (j < nb_strs)
	{
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(&s[i], 0, ft_substrlen(&s[i], c));
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (strs);
}
/*
int	main(int argc, char **argv)
{
	char	**strs;
	int		i;

	if (argc == 3)
	{
		strs = ft_split(argv[1], argv[2][0]);
		i = 0;
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
	}
	return (0);
}*/
