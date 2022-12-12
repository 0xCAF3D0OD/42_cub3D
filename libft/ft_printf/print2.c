/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:34:26 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/25 15:41:17 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	deal_with_width(int width, int printed, t_flags *flags)
{
	int	count;

	count = 0;
	if (is_sign(flags) && (flags->zero || !flags->width))
		count += print_sign(flags);
	while (count < width - printed)
	{
		if (flags->zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
	}
	if (is_sign(flags) && !flags->zero && flags->width)
	{
		count += print_sign(flags);
	}
	return (count);
}

int	print_s(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (len);
}

int	print_nbr(char *str, t_flags *flags)
{
	int	count;
	int	tmp;

	count = 0;
	if (flags->neg)
		count += print_sign(flags);
	if (flags->dot == 0 && *str == '0')
		return (0);
	if (flags->hashtag && !(is_hexa(flags->type) && *str == '0'))
	{
		if (flags->type == 'X')
			count += putstr_fd_ret("0X", 1);
		else
			count += putstr_fd_ret("0x", 1);
	}
	if (flags->dot != -1)
	{
		tmp = flags->zero;
		flags->zero = 1;
		count += deal_with_width(flags->dot, ft_strlen(str), flags);
		flags->zero = tmp;
	}
	count += putstr_fd_ret(str, 1);
	return (count);
}
