/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   map_check.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/24 00:00:00 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:23:29 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_walls(t_game *game)
{
	int	i;

	if (!game->map.full || game->map.rows < 3 || game->map.cols < 3)
		return (0);
	i = 0;
	while (i < game->map.cols)
	{
		if (!game->map.full[0] || !game->map.full[game->map.rows - 1])
			return (0);
		if (game->map.full[0][i] != '1'
			|| game->map.full[game->map.rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.rows)
	{
		if (!game->map.full[i])
			return (0);
		if (game->map.full[i][0] != '1'
			|| game->map.full[i][game->map.cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_rectangle(t_game *game)
{
	int	i;
	int	first_len;

	if (!game->map.full || !game->map.full[0])
		return (0);
	game->map.cols = ft_strlen(game->map.full[0]);
	first_len = game->map.cols;
	if (first_len == 0)
		return (0);
	i = 1;
	while (i < game->map.rows)
	{
		if (!game->map.full[i])
			return (0);
		if ((int)ft_strlen(game->map.full[i]) != first_len)
			return (0);
		i++;
	}
	return (1);
}

static int	check_valid_chars(t_game *game)
{
	int	y;
	int	x;

	if (!game->map.full)
		return (0);
	y = 0;
	while (y < game->map.rows)
	{
		if (!game->map.full[y])
			return (0);
		x = 0;
		while (x < game->map.cols && game->map.full[y][x])
		{
			if (game->map.full[y][x] != '1'
				&& game->map.full[y][x] != '0'
				&& game->map.full[y][x] != 'P'
				&& game->map.full[y][x] != 'E'
				&& game->map.full[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_map(t_game *game)
{
	if (!check_rectangle(game))
		error_exit("Error\nMap must be rectangular", game);
	count_map_elements(game);
	if (!check_walls(game))
		error_exit("Error\nMap must be surrounded by walls", game);
	if (!check_valid_chars(game))
		error_exit("Error\nInvalid character in map", game);
	if (game->map.player_count != 1)
		error_exit("Error\nMap must have exactly one player", game);
	if (game->map.exit_count != 1)
		error_exit("Error\nMap must have exactly one exit", game);
	if (game->map.collectibles < 1)
		error_exit("Error\nMap must have at least one collectible", game);
	if (!check_valid_path(game))
		error_exit("Error\nNo valid path to exit", game);
}
