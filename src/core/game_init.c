/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   game_init.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2026/01/16 23:04:06 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:23:18 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_game *game, char *map_file)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->img.stone = NULL;
	game->img.grass = NULL;
	game->img.player_left = NULL;
	game->img.player_right = NULL;
	game->img.flowers = NULL;
	game->img.exit_left = NULL;
	game->img.exit_right = NULL;
	game->img.finish = NULL;
	game->player.direction = 1;
	init_map(map_file, game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_exit("Error\nMLX initialization failed", game);
	game->win_width = game->map.cols * TILE_SIZE;
	game->win_height = game->map.rows * TILE_SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->win_width, game->win_height, "so_long");
	if (!game->win_ptr)
		error_exit("Error\nWindow creation failed", game);
	load_images(game);
	render_map(game);
}
