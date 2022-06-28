/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:18:04 by akayle            #+#    #+#             */
/*   Updated: 2022/06/27 20:18:24 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y - 1][x] == 'C')
		game->coins--;
	else if (game->map[y - 1][x] == 'E')
		game_over(game);
	game->map[y - 1][x] = 'P';
	game->map[y++][x] = '0';
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y + 1][x] == 'C')
		game->coins--;
	else if (game->map[y + 1][x] == 'E')
		game_over(game);
	game->map[y + 1][x] = 'P';
	game->map[y--][x] = '0';
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y][x - 1] == 'C')
		game->coins--;
	else if (game->map[y][x - 1] == 'E')
		game_over(game);
	game->map[y][x - 1] = 'P';
	game->map[y][x++] = '0';
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->p_coord.x;
	y = game->p_coord.y;
	step(game);
	if (game->map[y][x + 1] == 'C')
		game->coins--;
	else if (game->map[y][x + 1] == 'E')
		game_over(game);
	game->map[y][x + 1] = 'P';
	game->map[y][x--] = '0';
}
