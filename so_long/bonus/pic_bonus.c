/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:05:18 by akayle            #+#    #+#             */
/*   Updated: 2022/06/28 11:09:05 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_sprite(t_game *game, int i, int j)
{
	if (game->map[i][j])
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.floor, j * S_HEIGHT, i * S_WIDHT);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.wall, j * S_HEIGHT, i * S_WIDHT);
	else if (game->map[i][j] == 'R')
		mlx_put_image_to_window(game->mlx, game->win, \
							game->sprites.raider, j * S_HEIGHT, i * S_WIDHT);
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

void	update_sprites(t_game *game)
{	
	static int	tik = 0;

	if (tik == UPD_TIME)
	{	
		if (game->sprites.player != game->sprites.player_s)
			game->sprites.player = game->sprites.player_s;
		if (game->sprites.item == game->sprites.item_1)
			game->sprites.item = game->sprites.item_2;
		else if (game->sprites.item == game->sprites.item_2)
			game->sprites.item = game->sprites.item_1;
		tik++;
	}
	else if (tik == UPD_TIME + 15)
	{
		if (game->sprites.raider == game->sprites.raider_l)
			game->sprites.raider = game->sprites.raider_r;
		else if (game->sprites.raider == game->sprites.raider_r)
			game->sprites.raider = game->sprites.raider_l;
		raiders_move(game);
		tik = 0;
	}
	else
		tik++;
}

int	render_map(t_game *game)
{
	int		i;
	int		j;
	char	*steps;

	mlx_clear_window(game->mlx, game->win);
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			put_sprite(game, i, j);
		steps = ft_itoa(game->steps);
		mlx_string_put(game->mlx, game->win, 2, 15, 0xFF123456, "Steps: ");
		mlx_string_put(game->mlx, game->win, 45, 15, 0xFF123456, steps);
		free(steps);
	}
	update_sprites(game);
	return (0);
}

void	step(t_game *game)
{
	game->steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putchar_fd('\n', 1);
}
