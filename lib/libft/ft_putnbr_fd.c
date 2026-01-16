/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_putnbr_fd.c                                        :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/26 11:08:14 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:21:48 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_recursive(int n, int fd)
{
	char	c;

	if (n >= 10)
		putnbr_recursive(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	putnbr_recursive(n, fd);
}
