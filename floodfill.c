/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:32:52 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/12 08:33:41 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_complete *game, char **visited_map, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->mapwidth || y >= game->mapheight
		|| game->map[y][x] == '1' || visited_map[y][x] == 'V')
		return ;
	visited_map[y][x] = 'V';
	flood_fill(game, visited_map, x + 1, y);
	flood_fill(game, visited_map, x - 1, y);
	flood_fill(game, visited_map, x, y + 1);
	flood_fill(game, visited_map, x, y - 1);
}

void	flood_from_player(t_complete *game, char **visited_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if (game->map[i][j] == 'P')
				flood_fill(game, visited_map, j, i);
			j++;
		}
		i++;
	}
}
