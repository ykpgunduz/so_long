/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_split.c                                            :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/06/28 13:45:31 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:21:53 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arrlng(const char *s, char c)
{
	int	arrlng;

	arrlng = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
			return (arrlng);
		s++;
		arrlng++;
	}
	return (arrlng);
}

static int	ft_findrow(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i < size)
	{
		dest[i] = *src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_freeall(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**arr;

	i = 0;
	if (s == NULL)
		return (NULL);
	arr = malloc((ft_findrow(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			arr[i] = malloc(ft_arrlng(s, c) + 1);
			if (!arr[i])
				return (ft_freeall(arr, i - 1));
			ft_strncpy(arr[i], s, ft_arrlng(s, c));
			i++;
			s += ft_arrlng(s, c);
		}
	}
	arr[i] = NULL;
	return (arr);
}
