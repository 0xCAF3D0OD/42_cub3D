/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:15:23 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/25 15:38:52 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_printed_len_nbr(char *str, t_flags *flags)
{
	int	len;
	int	result;
	int	i;

	result = 0;
	len = ft_strlen(str);
	if (is_sign(flags) && !flags->zero)
		result++;
	if (flags->hashtag && !(is_hexa(flags->type) && *str == '0'))
		result += 2;
	if (*str == '0' && flags->dot == 0)
		return (0);
	i = 0;
	while (flags->dot != -1 && i < flags->dot - len)
		i++;
	result += i;
	return (result + len);
}

int	deal_with_i(int a, t_flags *flags)
{
	char	*str;
	int		count;
	int		printed;

	if (a < 0)
		flags->neg = 1;
	count = 0;
	str = ft_itoa_d(a);
	printed = get_printed_len_nbr(str, flags);
	if (flags->dash == 1)
		count += print_nbr(str, flags);
	count += deal_with_width(flags->width, printed, flags);
	if (flags->dash == 0)
		count += print_nbr(str, flags);
	free(str);
	return (count);
}

int	deal_with_u(int a, t_flags *flags)
{
	char	*str;
	int		count;
	int		printed;

	count = 0;
	str = ft_uitoa(a);
	printed = get_printed_len_nbr(str, flags);
	if (flags->dash == 1)
		count += print_nbr(str, flags);
	count += deal_with_width(flags->width, printed, flags);
	if (flags->dash == 0)
		count += print_nbr(str, flags);
	free(str);
	return (count);
}

int	deal_with_x(int a, t_flags *flags)
{
	char	*str;
	int		count;
	int		printed;

	count = 0;
	if (flags->type == 'x')
		str = ft_itoa_x(a, "0123456789abcdef");
	else
		str = ft_itoa_x(a, "0123456789ABCDEF");
	printed = get_printed_len_nbr(str, flags);
	if (flags->dash == 1)
		count += print_nbr(str, flags);
	count += deal_with_width(flags->width, printed, flags);
	if (flags->dash == 0)
		count += print_nbr(str, flags);
	free(str);
	return (count);
}

int	deal_with_p(void *p, t_flags *flags)
{
	int		count;
	int		printed;
	char	*str;

	flags->hashtag = 1;
	count = 0;
	str = ft_itoa_p((unsigned long long)p, "0123456789abcdef");
	printed = get_printed_len_nbr(str, flags);
	if (flags->dash == 1)
		count += print_nbr(str, flags);
	count += deal_with_width(flags->width, printed, flags);
	if (flags->dash == 0)
		count += print_nbr(str, flags);
	free(str);
	return (count);
}
