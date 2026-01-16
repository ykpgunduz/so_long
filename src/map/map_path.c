/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   map_path.c                                            :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/24 00:00:00 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:23:31 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	block_exit(char **map, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			if (map[y][x] == 'E')
				map[y][x] = '1';
		}
	}
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map.cols || y < 0 || y >= game->map.rows)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
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

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	block_exit(map_copy, game);
	flood_fill(map_copy, game->player.x, game->player.y, game);
	result = check_all_collected(map_copy, game);
	game->i = -1;
	while (++(game->i) < game->map.rows)
		free(map_copy[game->i]);
	free(map_copy);
	if (!result)
		return (0);
	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player.x, game->player.y, game);
	result = check_exit_reachable(map_copy, game);
	game->i = -1;
	while (++(game->i) < game->map.rows)
		free(map_copy[game->i]);
	free(map_copy);
	return (result);
}
