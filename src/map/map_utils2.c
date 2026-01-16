/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   map_utils2.c                                          :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/01/14 21:09:02 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:08:07 by yagunduz            ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		map_copy[i] = ft_strdup(game->map.full[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
