/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:25:58 by amuhleth          #+#    #+#             */
/*   Updated: 2022/07/25 18:46:39 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mmalloc.h"

int	main(void)
{
	t_mem	*list;
	char	*mem1;
	char	*mem2;
	char	*mem3;
	char	*mem4;

	list = NULL;

	print_mem(&list);

	mem1 = mmalloc(&list, 42);

	print_mem(&list);

	mem2 = mmalloc(&list, 1000);

	print_mem(&list);

	mfree(&list, mem1);

	print_mem(&list);

	mem3 = mmalloc(&list, 200);
	mem4 = mmalloc(&list, 50);

	print_mem(&list);

	mfree(&list, mem3);

	print_mem(&list);

	mfree(&list, mem4);

	print_mem(&list);

	mfree(&list, mem2);

	print_mem(&list);

	return (0);
}
