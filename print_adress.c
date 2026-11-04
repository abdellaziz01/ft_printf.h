/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:19:18 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/04 17:06:11 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hexa(char *res, int i)
{
	while (i >= 0)
	{
		print_char(res[i]);
		i--;
	}
}

int	print_adress(void *content)
{
	char			*hexa;
	unsigned long	p;
	char			res[100];
	int				i;

	hexa = "0123456789abcdef";
	if (!content)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	p = (unsigned long)content;
	i = 0;
	while (p >= 16)
	{
		res[i] = hexa[p % 16];
		p = p / 16;
		i++;
	}
	res[i] = hexa[p % 16];
	print_hexa(res, i);
	return (i + 3);
}
