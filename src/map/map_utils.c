/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagunduz <yagunduz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:15:09 by yagunduz          #+#    #+#             */
/*   Updated: 2026/01/14 22:17:36 by yagunduz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 5] != '/'
		&& filename[len - 4] == '.'
		&& filename[len - 3] == 'b'
		&& filename[len - 2] == 'e'
		&& filename[len - 1] == 'r')
		return (1);
	return (0);
}

void	remove_newline(char *line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

static void	find_player_pos(t_game *game)
{
	int	y;
	int	x;

	if (!game->map.full)
		return ;
	y = 0;
	while (y < game->map.rows)
	{
		if (!game->map.full[y])
			return ;
		x = 0;
		while (x < game->map.cols && game->map.full[y][x])
		{
			if (game->map.full[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	process_map_row(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->map.cols && game->map.full[y][x])
	{
		if (game->map.full[y][x] == 'P')
			game->map.player_count++;
		else if (game->map.full[y][x] == 'E')
		{
			game->map.exit_count++;
			game->map.exit_x = x;
			game->map.exit_y = y;
		}
		else if (game->map.full[y][x] == 'C')
			game->map.collectibles++;
		x++;
	}
}

void	count_map_elements(t_game *game)
{
	int	y;

	game->map.player_count = 0;
	game->map.exit_count = 0;
	game->map.collectibles = 0;
	if (!game->map.full)
		return ;
	y = 0;
	while (y < game->map.rows)
	{
		if (!game->map.full[y])
			break ;
		process_map_row(game, y);
		y++;
	}
	find_player_pos(game);
	game->player.collectibles = 0;
	game->player.moves = 0;
}
