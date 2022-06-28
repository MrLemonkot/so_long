/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:08:25 by akayle            #+#    #+#             */
/*   Updated: 2022/06/27 20:15:30 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_input_params(argc, argv);
	game = init_game(argv[1], S_HEIGHT, S_WIDHT);
	check_map(game);
	init_sprites(game);
	render_map(game);
	mlx_hook(game->win, 2, 0, key_hook, game);
	mlx_hook(game->win, 17, 0, game_over, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop(game->mlx);
	return (0);
}
