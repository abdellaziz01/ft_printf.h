/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:19:18 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/05 13:03:39 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hexa(char *res, int i)
{
	int	end;

	end = i;
	while (i >= 0)
	{
		if (print_char(res[i]) == -1)
			return (-1);
		i--;
	}
	return (end);
}

int	print_adress(void *content)
{
	char			*hexa;
	unsigned long	p;
	char			res[100];
	int				i;
	int				end;

	hexa = "0123456789abcdef";
	if (!content)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	p = (unsigned long)content;
	i = 0;
	while (p >= 16)
	{
		res[i] = hexa[p % 16];
		p = p / 16;
		i++;
	}
	res[i] = hexa[p % 16];
	end = print_hexa(res, i);
	if (end != -1)
		return (end + 3);
	return (-1);
}
