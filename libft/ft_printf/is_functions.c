/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:05:35 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/25 15:39:21 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_sign(t_flags *flags)
{
	return (flags->plus || flags->space || flags->neg);
}

int	is_type(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	is_hexa(int c)
{
	return (c == 'x' || c == 'X');
}

int	is_flag(int c)
{
	return (c == '-' || c == '0' || c == '+'
		|| c == ' ' || c == '#' || c == '.');
}
