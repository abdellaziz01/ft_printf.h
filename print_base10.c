/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:19:15 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/05 13:17:02 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_numbers(char *arr, int i)
{
	int	end;
	int	start;

	start = 0;
	if (arr[0] == '-')
	{
		if (print_char(arr[0]) == -1)
			return (-1);
		start = 1;
	}
	end = i;
	while (i >= start)
	{
		if (print_char(arr[i]) == -1)
			return (-1);
		i--;
	}
	return (end);
}

int	print_base10(int nb)
{
	char	arr[100];
	int		i;
	int		end;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		arr[0] = '-';
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		arr[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	arr[i] = nb % 10 + 48;
	end = print_numbers(arr, i);
	if (end != -1)
		return (end + 1);
	return (-1);
}
