/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagunduz <yagunduz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:00:00 by yagunduz          #+#    #+#             */
/*   Updated: 2026/01/14 18:59:35 by yagunduz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.full[y][x];
	put_image(game, game->img.grass, x, y);
	if (tile == '1')
		put_image(game, game->img.stone, x, y);
	else if (tile == 'C')
		put_image(game, game->img.flowers, x, y);
	else if (tile == 'E')
	{
		if (game->player.direction == 0)
			put_image(game, game->img.exit_left, x, y);
		else
			put_image(game, game->img.exit_right, x, y);
	}
	else if (tile == 'P')
	{
		if (game->player.direction == 0)
			put_image(game, game->img.player_left, x, y);
		else
			put_image(game, game->img.player_right, x, y);
	}
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
