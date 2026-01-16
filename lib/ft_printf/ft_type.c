/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_type.c                                             :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/08/12 17:22:32 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:20:51 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list *args, const char format)
{
	int	printed_chars;

	printed_chars = 0;
	if (format == 'c')
		printed_chars = ft_putchar(va_arg(*args, int));
	else if (format == 's')
		printed_chars = ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		printed_chars = ft_print_ptr((unsigned long)va_arg(*args, void *));
	else if (format == 'd' || format == 'i')
		printed_chars = ft_putnbr_d(va_arg(*args, int));
	else if (format == 'u')
		printed_chars = ft_putnbr_u(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed_chars = ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		printed_chars = write(1, "%", 1);
	else
		printed_chars = ft_error();
	return (printed_chars);
}
