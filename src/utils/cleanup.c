/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   cleanup.c                                             :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/24 00:00:00 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:07:10 by yagunduz            ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	destroy_images(t_game *game)
{
	if (game->img.stone)
		mlx_destroy_image(game->mlx_ptr, game->img.stone);
	if (game->img.grass)
		mlx_destroy_image(game->mlx_ptr, game->img.grass);
	if (game->img.player_left)
		mlx_destroy_image(game->mlx_ptr, game->img.player_left);
	if (game->img.player_right)
		mlx_destroy_image(game->mlx_ptr, game->img.player_right);
	if (game->img.flowers)
		mlx_destroy_image(game->mlx_ptr, game->img.flowers);
	if (game->img.exit_left)
		mlx_destroy_image(game->mlx_ptr, game->img.exit_left);
	if (game->img.exit_right)
		mlx_destroy_image(game->mlx_ptr, game->img.exit_right);
	if (game->img.finish)
		mlx_destroy_image(game->mlx_ptr, game->img.finish);
}

void	cleanup_game(t_game *game)
{
	destroy_images(game);
	free_map(game->map.full);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

int	close_game(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
