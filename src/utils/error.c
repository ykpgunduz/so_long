/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   error.c                                               :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/25 00:00:00 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/17 00:04:07 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

void	error_exit(char *message, t_game *game)
{
	get_next_line(-1);
	ft_printf("%s\n", message);
	if (game)
	{
		if (game->map.full)
			free_map(game->map.full);
		if (game->mlx_ptr)
		{
			destroy_images(game);
			if (game->win_ptr)
				mlx_destroy_window(game->mlx_ptr, game->win_ptr);
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
	}
	exit(1);
}
