/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:16:53 by akayle            #+#    #+#             */
/*   Updated: 2022/06/27 20:17:12 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_symbols(t_game *game)
{
	int		i;
	int		j;
	char	chrs[6];

	i = game->map_height;
	ft_strlcpy(chrs, "01CEP", 6);
	while (--i >= 0)
	{
		j = 0;
		while (j < game->map_widht)
		{
			if (!ft_strchr(chrs, game->map[i][j]))
				error("Map contains wrong symbol(s).");
			j++;
		}
	}
	return (0);
}

int	check_map_size(t_game *game)
{
	int	i;

	if (!game->map_height || !game->map_widht)
		error("Map has zero lines.");
	i = 0;
	while (++i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != game->map_widht)
			error("Map size is not valid.");
	}
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		if (i == 0 || i == game->map_height - 1)
		{
			while (j < game->map_widht)
			{
				if (game->map[i][j] != '1')
					error("Map has broken walls.");
				j++;
			}
		}
		if (game->map[i][0] != '1' || game->map[i][game->map_widht - 1] != '1')
			error("Map has broken walls.");
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	check_map_symbols(game);
	check_map_size(game);
	check_map_walls(game);
	map_obj_count(game);
	if (!game->coins)
		error("Map does not contains any colectible.");
	else if (!game->exits)
		error("Map does not contains any exit.");
	else if (game->players != 1)
		error("Map contains wrong number of players.");
	else if (game->map_height <= 1)
		error("Map is too small.");
	else if (!game->map_height && !game->map_widht)
		error("Map is empty.");
	return (0);
}