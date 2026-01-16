/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_putstr_fd.c                                        :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/26 11:08:24 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:21:51 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
