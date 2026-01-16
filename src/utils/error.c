/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   error.c                                               :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/25 00:00:00 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/17 01:06:59 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
