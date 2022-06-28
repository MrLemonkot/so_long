/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:21:23 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:31:00 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "liba/mlx/mlx.h"
# include "liba/libft/libft.h"

# define S_HEIGHT	60
# define S_WIDHT	60
# define UPD_TIME	25

# define WALL		"./pic/wall.xpm"
# define FLOOR		"./pic/Ground.xpm"
# define EXIT_CL	"./pic/door_cl.xpm"
# define EXIT_OP	"./pic/door_op.xpm"
# define COIN_1		"./pic/coin_1.xpm"
# define COIN_2		"./pic/coin_2.xpm"
# define PLAYER_S	"./pic/tire.xpm"
# define PLAYER_L	"./pic/cat2.xpm"
# define PLAYER_R	"./pic/cat.xpm"
# define RAIDER_L	"./pic/V1.xpm"
# define RAIDER_R	"./pic/V2.xpm"

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
	void	*item_1;
	void	*item_2;
	void	*exit;
	void	*exit_cl;
	void	*exit_op;
	void	*player;
	void	*player_s;
	void	*player_l;
	void	*player_r;
	void	*raider;
	void	*raider_l;
	void	*raider_r;
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
	int			raiders;
	int			steps;
	t_assets	sprites;
	t_coord		p_coord;
	t_coord		r_coord[10];
}				t_game;

int		error(char *message);
int		game_over(t_game *game);
int		end_game(t_game *game);
int		check_input_params(int argc, char **argv);
int		sym_count(t_game *game, char symbol);
int		check_sprites(t_assets *sprites);
void	free2d(char **arr, int len);
void	map_obj_count(t_game *game);
int		check_map_symbols(t_game *game);
int		check_map_size(t_game *game);
int		check_map_walls(t_game *game);
int		check_map(t_game *game);
char	*file_to_array(char *filename);
int		count_lines(char *filename);
t_game	*init_game(char *filename, int s_height, int s_widht);
void	init_player_sprites(t_game *game);
void	init_env_sprites(t_game *game);
void	init_raiders(t_game *game);
void	init_all_sprites(t_game *game);
int		render_map(t_game *game);
void	put_sprite(t_game *game, int i, int j);
void	update_sprites(t_game *game);
void	step(t_game *game);
int		key_hook(int keycode, t_game *game);
int		is_end(t_game *game, int keycode);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
int		raiders_move(t_game *game);
void	sel_direction(t_game *game, int r_num, int direction);
void	raiders_move_up(t_game *game, int r_num);
void	raiders_move_down(t_game *game, int r_num);
void	raiders_move_left(t_game *game, int r_num);
void	raiders_move_right(t_game *game, int r_num);
#endif
