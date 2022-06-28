/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:38:24 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:47:17 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	is_end(t_game *game, int keycode)
{
	int	x;
	int	y;
	int	c;

	x = game->p_coord.x;
	y = game->p_coord.y;
	c = game->coins;
	if (keycode == KEY_W && game->map[y - 1][x] == 'E' && c)
		return (0);
	else if (keycode == KEY_S && game->map[y + 1][x] == 'E' && c)
		return (0);
	else if (keycode == KEY_A && game->map[y][x - 1] == 'E' && c)
		return (0);
	else if (keycode == KEY_D && game->map[y][x + 1] == 'E' && c)
		return (0);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;
	int	end_flag;

	x = game->p_coord.x;
	y = game->p_coord.y;
	end_flag = is_end(game, keycode);
	if (keycode == KEY_W && game->map[y - 1][x] != '1' \
					&& end_flag)
		move_up(game);
	else if (keycode == KEY_S && game->map[y + 1][x] != '1' \
					&& end_flag)
		move_down(game);
	else if (keycode == KEY_A && game->map[y][x - 1] != '1' \
					&& end_flag)
		move_left(game);
	else if (keycode == KEY_D && game->map[y][x + 1] != '1' \
					&& end_flag)
		move_right(game);
	else if (keycode == KEY_ESC)
		game_over(game);
	if (game->coins == 0)
		game->sprites.exit = game->sprites.exit_op;
	return (0);
}
