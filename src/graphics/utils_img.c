/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   utils_img.c                                           :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/12/24 00:00:00 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/17 00:01:19 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	*load_image(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!img)
	{
		ft_printf("Error\nFailed to load image: %s\n", path);
		ft_printf("Trying to create a blank image instead...\n");
		img = mlx_new_image(game->mlx_ptr, TILE_SIZE, TILE_SIZE);
		if (!img)
		{
			cleanup_game(game);
			exit(1);
		}
	}
	return (img);
}

void	load_images(t_game *game)
{
	game->img.stone = load_image(game, "./assets/textures/stone.xpm");
	game->img.grass = load_image(game, "./assets/textures/grass.xpm");
	game->img.flowers = load_image(game, "./assets/textures/flowers.xpm");
	game->img.finish = load_image(game, "./assets/textures/finish.xpm");
	game->img.player_left = load_image(game,
			"./assets/textures/player-left.xpm");
	game->img.player_right = load_image(game,
			"./assets/textures/player-right.xpm");
	game->img.exit_left = load_image(game,
			"./assets/textures/exit-left.xpm");
	game->img.exit_right = load_image(game,
			"./assets/textures/exit-right.xpm");
}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img,
		x * TILE_SIZE, y * TILE_SIZE);
}
