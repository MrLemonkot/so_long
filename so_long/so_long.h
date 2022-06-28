/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:30:37 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:34:23 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "liba/mlx/mlx.h"
# include "liba/libft/libft.h"

# define S_HEIGHT	60
# define S_WIDHT	60

# define WALL		"./pic/wall.xpm"
# define FLOOR		"./pic/Ground.xpm"
# define EXIT		"./pic/door_cl.xpm"
# define COIN		"./pic/coin_1.xpm"
# define PLAYER		"./pic/player.xpm"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_assets
{
	void	*wall;
	void	*floor;
	void	*item;
	void	*exit;
	void	*player;
}				t_assets;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			s_height;
	int			s_widht;
	int			map_height;
	int			map_widht;
	int			coins;
	int			exits;
	int			players;
	int			steps;
	t_assets	sprites;
	t_coord		p_coord;
}				t_game;

int		error(char *message);
int		game_over(t_game *game);
int		check_input_params(int argc, char **argv);
void	free2d(char **arr, int len);
int		sym_count(t_game *game, char symbol);
void	map_obj_count(t_game *game);
int		check_sprites(t_assets *sprites);
int		check_map_symbols(t_game *game);
int		check_map_size(t_game *game);
int		check_map_walls(t_game *game);
int		check_map(t_game *game);
char	*file_to_array(char *filename);
int		count_lines(char *filename);
t_game	*init_game(char *filename, int s_height, int s_widht);
void	init_sprites(t_game *game);
int		render_map(t_game *game);
void	put_sprite(t_game *game, int i, int j);
void	step(t_game *game);
int		key_hook(int keycode, t_game *game);
int		is_end(t_game *game, int keycode);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
#endif
