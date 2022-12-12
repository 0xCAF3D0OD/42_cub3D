/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:15:11 by amuhleth          #+#    #+#             */
/*   Updated: 2021/12/07 15:40:03 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->dash = 0;
	flags->zero = 0;
	flags->dot = -1;
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->type = 0;
	flags->neg = 0;
}

int	select_type(int c, va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += deal_with_c(va_arg(args, int), flags);
	if (c == 's')
		count += deal_with_s(va_arg(args, char *), flags);
	if (c == 'i' || c == 'd')
		count += deal_with_i(va_arg(args, int), flags);
	if (c == 'u')
		count += deal_with_u(va_arg(args, int), flags);
	if (c == '%')
		count += deal_with_percent(flags);
	if (c == 'x' || c == 'X')
		count += deal_with_x(va_arg(args, int), flags);
	if (c == 'p')
		count += deal_with_p(va_arg(args, void *), flags);
	return (count);
}

int	global_process(char *str, va_list args)
{
	t_flags	*flags;
	int		count;

	count = 0;
	while (*str)
	{
		flags = ft_calloc(sizeof(t_flags), 1);
		init_flags(flags);
		if (*str == '%' && *(str + 1))
		{
			str = flags_parser(str, flags);
			if (flags->zero && flags->dot != -1
				&& flags->dot < flags->width)
				flags->zero = 0;
			if (is_type(*str))
				count += select_type(*str, args, flags);
			else if (*str)
				count += putchar_fd_ret(*str, 1);
		}
		else if (*str != '%')
			count += putchar_fd_ret(*str, 1);
		free(flags);
		str++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int		count;
	va_list	args;
	char	*save;

	save = ft_strdup(input);
	count = 0;
	va_start(args, input);
	count += global_process(save, args);
	va_end(args);
	free(save);
	return (count);
}
