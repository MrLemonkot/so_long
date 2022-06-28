/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:44:32 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 13:47:31 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_input_params(argc, argv);
	game = init_game(argv[1], S_HEIGHT, S_WIDHT);
	check_map(game);
	init_all_sprites(game);
	render_map(game);
	mlx_hook(game->win, 2, 0, key_hook, game);
	mlx_hook(game->win, 17, 0L, game_over, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop(game->mlx);
	return (0);
}
