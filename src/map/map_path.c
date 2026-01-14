/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagunduz <yagunduz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:00:00 by yagunduz          #+#    #+#             */
/*   Updated: 2026/01/14 18:59:35 by yagunduz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**copy_map(t_game *game)
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

static void	flood_fill(char **map, int x, int y, t_game *game, int with_exit)
{
	if (x < 0 || x >= game->map.cols || y < 0 || y >= game->map.rows)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E' && !with_exit)
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game, with_exit);
	flood_fill(map, x - 1, y, game, with_exit);
	flood_fill(map, x, y + 1, game, with_exit);
	flood_fill(map, x, y - 1, game, with_exit);
}

static int	check_all_collected(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	check_exit_reachable(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_valid_path(t_game *game)
{
	char	**map_copy;
	int		result;
	int		i;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player.x, game->player.y, game, 0);
	result = check_all_collected(map_copy, game);
	i = -1;
	while (++i < game->map.rows)
		free(map_copy[i]);
	free(map_copy);
	if (!result)
		return (0);
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player.x, game->player.y, game, 1);
	result = check_exit_reachable(map_copy, game);
	i = -1;
	while (++i < game->map.rows)
		free(map_copy[i]);
	free(map_copy);
	return (result);
}
