/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsi_numb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:18:02 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/04 16:37:30 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsi_numb(unsigned int nb)
{
	char	arr[100];
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
		print_char(arr[i]);
		i--;
	}
	return (end);
}
