/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   so_long.h                                             :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/11/25 15:54:59 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:20:34 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

# define TILE_SIZE 64
# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define EVENT_CLOSE_BTN 17

typedef struct s_player
{
	int		x;
	int		y;
	int		collectibles;
	int		moves;
	int		direction;
}	t_player;

typedef struct s_map
{
	char	**full;
	int		rows;
	int		cols;
	int		player_count;
	int		exit_count;
	int		collectibles;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_img
{
	void	*stone;
	void	*grass;
	void	*player_left;
	void	*player_right;
	void	*flowers;
	void	*exit_left;
	void	*exit_right;
	void	*finish;
}	t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_img		img;
	int			win_width;
	int			win_height;
	int			i;
}	t_game;

void	init_game(t_game *game, char *map_file);
int		close_game(t_game *game);

void	init_map(char *filename, t_game *game);
int		check_extension(char *filename);
void	validate_map(t_game *game);
int		check_valid_path(t_game *game);
void	remove_newline(char *line);
void	count_map_elements(t_game *game);
char	**copy_map(t_game *game);

void	load_images(t_game *game);
void	render_map(t_game *game);
void	put_image(t_game *game, void *img, int x, int y);

int		key_handler(int keycode, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

void	free_map(char **map);
void	cleanup_game(t_game *game);
void	error_exit(char *message, t_game *game);

#endif
