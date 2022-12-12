/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:15:13 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/25 15:38:59 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_printed_len_s(char *str, t_flags *flags)
{
	int	len;

	len = (int)ft_strlen(str);
	if (flags->dot == -1)
		return (len);
	else
	{
		if (flags->dot < len)
			return (flags->dot);
		else
			return (len);
	}
}

int	deal_with_s(char *str, t_flags *flags)
{
	int	count;
	int	printed;

	count = 0;
	if (!str)
		str = "(null)";
	printed = get_printed_len_s(str, flags);
	if (flags->dash == 1)
		count += print_s(str, printed);
	count += deal_with_width(flags->width, printed, flags);
	if (flags->dash == 0)
		count += print_s(str, printed);
	return (count);
}

int	deal_with_c(char c, t_flags *flags)
{
	int	count;

	count = 1;
	if (flags->dash == 1)
		ft_putchar_fd(c, 1);
	count += deal_with_width(flags->width, 1, flags);
	if (flags->dash == 0)
		ft_putchar_fd(c, 1);
	return (count);
}

int	deal_with_percent(t_flags *flags)
{
	int	count;

	count = 1;
	if (flags->dash == 1)
		ft_putchar_fd('%', 1);
	count += deal_with_width(flags->width, 1, flags);
	if (flags->dash == 0)
		ft_putchar_fd('%', 1);
	return (count);
}
