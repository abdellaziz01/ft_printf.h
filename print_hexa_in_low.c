/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_in_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:18:43 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/04 17:05:33 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_in_low(unsigned int nb)
{
	char	*hexa;
	int		end;
	int		i;
	char	res[100];

	hexa = "0123456789abcdef";
	i = 0;
	while (nb >= 16)
	{
		res[i] = hexa[nb % 16];
		nb = nb / 16;
		i++;
	}
	res[i] = hexa[nb % 16];
	end = i + 1;
	while (i >= 0)
	{
		print_char(res[i]);
		i--;
	}
	return (end);
}
