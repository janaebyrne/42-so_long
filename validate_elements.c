/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:23:27 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/12 09:09:01 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map_characters(t_complete *game)
{
	int		i;
	int		j;
	char	cell;

	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			cell = game->map[i][j];
			if (cell != '1' && cell != '0' && cell != 'P' && cell != 'E'
				&& cell != 'C' && cell != '\n')
			{
				ft_printf("Error: Invalid char '%c' at (%d, %d)\n", cell, i, j);
				exit_point(game);
			}
			j++;
		}
		i++;
	}
}

void	count_map_elements(t_complete *game)
{
	int		i;
	char	cell;
	int		j;

	i = 0;
	game->exit_count = 0;
	game->collectable_count = 0;
	game->player_moves = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			cell = game->map[i][j];
			if (cell == 'E')
				game->exit_count++;
			if (cell == 'C')
				game->collectable_count++;
			if (cell == 'P')
				game->player_moves++;
			j++;
		}
		i++;
	}
}

void	validate_elements(t_complete *game)
{
	validate_map_characters(game);
	count_map_elements(game);
	if (game->exit_count != 1 || game->collectable_count < 1
		|| game->player_moves != 1)
	{
		ft_printf("Map usage: 1 Exit(E), 1+ Collectables(C) & 1 start(P)\n");
		exit_point(game);
	}
	game->player_moves = 0;
}
