/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:19:23 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/05 13:18:05 by abdait-o         ###   ########.fr       */
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

int	real_res(const char *format, va_list *ptr)
{
	int	t;
	int	i;
	int	lenght;

	t = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			lenght = return_value(format[i + 1], ptr);
			i++;
		}
		else if (format[i] != '%')
			lenght = print_char(format[i]);
		if (lenght == -1)
			return (-1);
		t = t + lenght;
		i++;
	}
	return (t);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	ptr;

	if (!format)
		return (-1);
	va_start(ptr, format);
	res = real_res(format, &ptr);
	va_end(ptr);
	return (res);
}
