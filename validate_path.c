/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janaebyrne <janaebyrne@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:26 by janaebyrne        #+#    #+#             */
/*   Updated: 2024/09/08 17:53:11 by janaebyrne       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_visited_map(char **visited_map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited_map[i]);
		i++;
	}
	free(visited_map);
}

static char	**init_visited_map(t_complete *game)
{
	char	**visited_map;
	int		i;

	i = 0;
	visited_map = malloc(game->mapheight * sizeof(char *));
	if (!visited_map)
		return (NULL);
	while (i < game->mapheight)
	{
		visited_map[i] = ft_strdup(game->map[i]);
		if (!visited_map[i])
		{
			while (i > 0)
				free(visited_map[--i]);
			free(visited_map);
			return (NULL);
		}
		i++;
	}
	return (visited_map);
}

void	check_reachable(t_complete *game, char **visited_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E')
				&& visited_map[i][j] != 'V')
			{
				ft_printf("Invalid map: Unreachable collectable or exit\n");
				free_map(visited_map, game->mapheight);
				exit_point(game);
			}
			j++;
		}
		i++;
	}
}

void	check_valid_path(t_complete *game)
{
	char	**visited_map;

	visited_map = init_visited_map(game);
	if (!visited_map)
	{
		ft_printf("Memory allocation failed\n");
		exit_point(game);
	}
	flood_from_player(game, visited_map);
	check_reachable(game, visited_map);
	free_visited_map(visited_map, game->mapheight);
}
