/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:54:19 by akayle            #+#    #+#             */
/*   Updated: 2022/06/27 19:55:25 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y - 1][x] == 'C')
		game->coins--;
	else if (game->map[y - 1][x] == 'E')
		end_game(game);
	else if (game->map[y - 1][x] == 'R')
		game_over(game);
	game->map[y - 1][x] = 'P';
	game->map[y][x] = '0';
	step(game);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y + 1][x] == 'C')
		game->coins--;
	else if (game->map[y + 1][x] == 'E')
		end_game(game);
	else if (game->map[y + 1][x] == 'R')
		game_over(game);
	game->map[y + 1][x] = 'P';
	game->map[y][x] = '0';
	step(game);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y][x - 1] == 'C')
		game->coins--;
	else if (game->map[y][x - 1] == 'E')
		end_game(game);
	else if (game->map[y][x - 1] == 'R')
		game_over(game);
	game->map[y][x - 1] = 'P';
	game->map[y][x] = '0';
	game->sprites.player = game->sprites.player_l;
	step(game);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	if (game->map[y][x + 1] == 'C')
		game->coins--;
	else if (game->map[y][x + 1] == 'E')
		end_game(game);
	else if (game->map[y][x + 1] == 'R')
		game_over(game);
	game->map[y][x + 1] = 'P';
	game->map[y][x] = '0';
	game->sprites.player = game->sprites.player_r;
	step(game);
}
