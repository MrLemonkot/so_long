/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:11:21 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:48:38 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

int	game_over(t_game *game)
{
	ft_putstr_fd("Game end\n", 2);
	mlx_destroy_window(game->mlx, game->win);
	free2d(game->map, game->map_height);
	free(game);
	exit(0);
	return (1);
}

int	end_game(t_game *game)
{
	ft_putstr_fd("You win :)\n", 2);
	mlx_destroy_window(game->mlx, game->win);
	free2d(game->map, game->map_height);
	free(game);
	exit(0);
	return (1);
}
