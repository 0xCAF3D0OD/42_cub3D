/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:23:41 by amuhleth          #+#    #+#             */
/*   Updated: 2021/11/25 15:39:49 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_fd_ret(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	putstr_fd_ret(char *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
	return (i);
}

int	print_sign(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->neg)
	{
		count += putchar_fd_ret('-', 1);
		flags->neg = 0;
	}
	else if (flags->plus)
	{
		count += putchar_fd_ret('+', 1);
		flags->plus = 0;
	}
	else if (flags->space && flags->type != 's')
	{
		count += putchar_fd_ret(' ', 1);
		flags->space = 0;
	}
	return (count);
}

int	print_hashtag(void)
{
	ft_putstr_fd("0x", 1);
	return (2);
}
