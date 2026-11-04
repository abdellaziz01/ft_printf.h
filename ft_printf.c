/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:19:23 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/04 16:27:19 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	return_value(char c, va_list *ptr)
{
	if (c == 'c')
		return (print_char(va_arg(*ptr, int)));
	if (c == 's')
		return (print_string(va_arg(*ptr, char *)));
	if (c == 'p')
		return (print_adress(va_arg(*ptr, void *)));
	if (c == 'i' || c == 'd')
		return (print_base10(va_arg(*ptr, int)));
	if (c == 'u')
		return (print_unsi_numb(va_arg(*ptr, unsigned int)));
	if (c == 'x')
		return (print_hexa_in_low(va_arg(*ptr, unsigned int)));
	if (c == 'X')
		return (print_hexa_in_upp(va_arg(*ptr, unsigned int)));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		t;
	int		i;
	va_list	ptr;

	t = 0;
	if (!format)
		return (-1);
	va_start(ptr, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			t = t + return_value(format[i + 1], &ptr);
			i++;
		}
		else if (format[i] != '%')
			t = t + print_char(format[i]);
		i++;
	}
	va_end(ptr);
	return (t);
}
