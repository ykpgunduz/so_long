/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_strdup.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/06/28 13:45:23 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:11:37 by yagunduz            ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s, len);
	copy[len] = '\0';
	return (copy);
}
