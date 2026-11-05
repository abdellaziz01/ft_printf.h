/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsi_numb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:18:02 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/05 12:40:24 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsi_numb(unsigned int nb)
{
	char	arr[20];
	int		i;
	int		end;

	i = 0;
	while (nb > 9)
	{
		arr[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	arr[i] = nb % 10 + 48;
	end = i + 1;
	while (i >= 0)
	{
		if (print_char(arr[i]) == -1)
			return (-1);
		i--;
	}
	return (end);
}
