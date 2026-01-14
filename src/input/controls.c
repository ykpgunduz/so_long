/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagunduz <yagunduz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:06:19 by yagunduz          #+#    #+#             */
/*   Updated: 2026/01/14 18:59:35 by yagunduz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <unistd.h>

static void	find_exit_position(t_game *game, int *exit_x, int *exit_y)
{
	int	i;
	int	j;

	*exit_x = -1;
	*exit_y = -1;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.full[i][j] == 'E')
			{
				*exit_x = j;
				*exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	show_finish_and_close(t_game *game)
{
	int	exit_x;
	int	exit_y;

	find_exit_position(game, &exit_x, &exit_y);
	if (exit_x != -1)
	{
		put_image(game, game->img.grass, exit_x, exit_y);
		put_image(game, game->img.finish, exit_x, exit_y);
		mlx_do_sync(game->mlx_ptr);
	}
	ft_printf("Congratulations! You won in %d moves!\n",
		game->player.moves);
	close_game(game);
}

static void	check_win(t_game *game)
{
	if (game->player.collectibles == game->map.collectibles
		&& game->map.full[game->player.y][game->player.x] == 'E')
	{
		show_finish_and_close(game);
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	next_tile;
	char	old_tile;

	next_tile = game->map.full[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'E' && game->player.collectibles != game->map.collectibles)
		return ;
	if (next_tile == 'C')
	{
		game->player.collectibles++;
		game->map.full[new_y][new_x] = '0';
	}
	old_tile = '0';
	if (game->player.x == game->map.exit_x
		&& game->player.y == game->map.exit_y)
		old_tile = 'E';
	game->map.full[game->player.y][game->player.x] = old_tile;
	game->player.x = new_x;
	game->player.y = new_y;
	if (next_tile != 'E')
		game->map.full[new_y][new_x] = 'P';
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	render_map(game);
	check_win(game);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W_KEY || keycode == UP_ARROW)
		move_player(game, game->player.x, game->player.y - 1);
	else if (keycode == S_KEY || keycode == DOWN_ARROW)
		move_player(game, game->player.x, game->player.y + 1);
	else if (keycode == A_KEY || keycode == LEFT_ARROW)
	{
		game->player.direction = 0;
		move_player(game, game->player.x - 1, game->player.y);
	}
	else if (keycode == D_KEY || keycode == RIGHT_ARROW)
	{
		game->player.direction = 1;
		move_player(game, game->player.x + 1, game->player.y);
	}
	return (0);
}
