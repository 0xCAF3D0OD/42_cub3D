/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:53:57 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/25 15:39:41 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_dot(char *str, t_flags *flags)
{
	flags->dot = 0;
	str++;
	while (ft_isdigit(*str))
	{
		flags->dot = (flags->dot * 10) + (*str - '0');
		str++;
	}
	return (str);
}

void	parse_dash(t_flags *flags)
{
	flags->dash = 1;
	flags->zero = 0;
}

void	parse_sign(char c, t_flags *flags)
{
	if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
}

void	parse_width(char c, t_flags *flags)
{
	flags->width = (flags->width * 10) + (c - '0');
}

char	*flags_parser(char *str, t_flags *flags)
{
	str++;
	while (*str)
	{
		if (!is_type(*str) && !is_flag(*str) && !ft_isdigit(*str))
			break ;
		if (*str == '+' || *str == ' ')
			parse_sign(*str, flags);
		if (*str == '#')
			flags->hashtag = 1;
		if (*str == '0' && flags->width == 0 && flags->dash == 0)
			flags->zero = 1;
		if (*str == '.')
			str = parse_dot(str, flags);
		if (*str == '-')
			parse_dash(flags);
		if (ft_isdigit(*str))
			parse_width(*str, flags);
		if (is_type(*str))
		{
			flags->type = *str;
			break ;
		}
		str++;
	}
	return (str);
}
