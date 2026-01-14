/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagunduz <yagunduz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:15:00 by yagunduz          #+#    #+#             */
/*   Updated: 2026/01/14 19:21:32 by yagunduz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_d(int number)
{
	int	printed_chars;

	printed_chars = 0;
	if (number < 0)
	{
		printed_chars += ft_putchar('-');
		if (number == -2147483648)
		{
			printed_chars += ft_putchar('2');
			number = 147483648;
		}
		else
			number = -number;
	}
	if (number >= 10)
		printed_chars += ft_putnbr_d(number / 10);
	printed_chars += ft_putchar(number % 10 + '0');
	return (printed_chars);
}

int	ft_putnbr_u(unsigned int number)
{
	int	printed_chars;

	printed_chars = 0;
	if (number >= 10)
		printed_chars += ft_putnbr_u(number / 10);
	printed_chars += ft_putchar(number % 10 + '0');
	return (printed_chars);
}

int	ft_print_hex_ptr(unsigned long number, const char format)
{
	char	*hex_lower;
	char	*hex_upper;
	int		printed_chars;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	printed_chars = 0;
	if (number >= 16)
		printed_chars += ft_print_hex_ptr(number / 16, format);
	if (format == 'x')
		printed_chars += ft_putchar(hex_lower[number % 16]);
	else
		printed_chars += ft_putchar(hex_upper[number % 16]);
	return (printed_chars);
}
