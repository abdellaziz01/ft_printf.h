/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:19:15 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/04 17:07:33 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_numbers(char *arr, int i, int start)
{
	while (i >= start)
	{
		print_char(arr[i]);
		i--;
	}
}

int	print_base10(int nb)
{
	char	arr[100];
	int		i;
	int		start;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		print_char('-');
		nb = -nb;
		i = 1;
	}
	start = i;
	while (nb > 9)
	{
		arr[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	arr[i] = nb % 10 + 48;
	print_numbers(arr, i, start);
	return (i + 1);
}
