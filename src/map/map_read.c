/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   map_read.c                                            :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/26 11:17:01 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:07:50 by yagunduz            ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	get_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	get_next_line(-1);
	return (height);
}

static void	fill_map(char *filename, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nCannot open map file", game);
	i = 0;
	while (i < game->map.rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		remove_newline(line);
		game->map.full[i] = line;
		i++;
	}
	game->map.full[i] = NULL;
	close(fd);
	get_next_line(-1);
}

void	init_map(char *filename, t_game *game)
{
	if (!check_extension(filename))
		error_exit("Error\nMap file must be .ber", NULL);
	game->map.rows = get_map_height(filename);
	if (game->map.rows == 0)
		error_exit("Error\nEmpty map or file error", NULL);
	game->map.full = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.full)
		error_exit("Error\nMemory allocation failed", game);
	fill_map(filename, game);
	validate_map(game);
}
