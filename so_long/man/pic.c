/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:18:44 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 10:34:00 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_sprite(t_game *game, int i, int j)
{
	if (game->map[i][j])
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.floor, j * S_HEIGHT, i * S_WIDHT);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.wall, j * S_HEIGHT, i * S_WIDHT);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.exit, j * S_HEIGHT, i * S_WIDHT);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.item, j * S_HEIGHT, i * S_WIDHT);
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.player, j * S_HEIGHT, i * S_WIDHT);
		game->p_coord.x = j;
		game->p_coord.y = i;
	}	
}

int	render_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			put_sprite(game, i, j);
	}
	return (0);
}

void	step(t_game *game)
{
	game->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putchar_fd('\n', 1);
}
