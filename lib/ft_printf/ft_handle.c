/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_handle.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/08/12 17:27:41 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:09:39 by yagunduz            ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[index])
		write(1, &str[index++], 1);
	return (index);
}

int	ft_print_ptr(unsigned long number)
{
	int	printed_chars;

	if (number == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	printed_chars = 2 + ft_print_hex_ptr(number, 'x');
	return (printed_chars);
}

int	ft_print_hex(unsigned int number, const char format)
{
	char	*hex_lower;
	char	*hex_upper;
	int		printed_chars;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	printed_chars = 0;
	if (number >= 16)
		printed_chars += ft_print_hex(number / 16, format);
	if (format == 'x')
		printed_chars += ft_putchar(hex_lower[number % 16]);
	else
		printed_chars += ft_putchar(hex_upper[number % 16]);
	return (printed_chars);
}
