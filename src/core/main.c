/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yagunduz <yagunduz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:05:57 by yagunduz          #+#    #+#             */
/*   Updated: 2026/01/13 17:42:44 by yagunduz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map.ber>\n");
		return (1);
	}
	init_game(&game, argv[1]);
	mlx_hook(game.win_ptr, EVENT_CLOSE_BTN, 0, close_game, &game);
	mlx_key_hook(game.win_ptr, key_handler, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
