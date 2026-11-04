/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_in_upp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:18:32 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/04 16:55:35 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_in_upp(unsigned int nb)
{
	char	res[100];
	int		i;
	int		end;
	char	*hexa;

	hexa = "0123456789ABCDEF";
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
