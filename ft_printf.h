/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:19:29 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/04 16:51:18 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_adress(void *content);
int	print_string(const char *str);
int	print_base10(int nb);
int	print_unsi_numb(unsigned int nb);
int	print_hexa_in_low(unsigned int nb);
int	print_hexa_in_upp(unsigned int nb);

#endif
