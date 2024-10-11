/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:26:25 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/11 19:45:44 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontalwalls(t_complete *game)
{
	int	width;
	int	i;

	i = 0;
	width = game->mapwidth;
	while (i < width)
	{
		if (game->map[0][i] != '1' || game->map[game->mapheight - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	verticalwalls(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->mapwidth;
	while (height < game->mapheight)
	{
		if (game->map[height][0] != '1' || game->map[height][width - 1] != '1')
			return (0);
		height++;
	}
	return (1);
}

void	if_walls(t_complete *game)
{
	int	vertical_walls;
	int	horizontal_walls;

	vertical_walls = verticalwalls(game);
	horizontal_walls = horizontalwalls(game);
	if (!vertical_walls || !horizontal_walls)
	{
		ft_printf("Map is missing walls\n");
		exit_point(game);
	}
}

int	is_rectange(t_complete *game)
{
	int	i;
	int	row_length;

	i = 0;
	while (i < game->mapheight)
	{
		row_length = ft_strlen(game->map[i]);
		if (game->map[i][row_length - 1] == '\n')
			row_length--;
		if (row_length != game->mapwidth)
		{
			ft_printf("This map is not a rectangle\n");
			exit_point(game);
		}
		i++;
	}
	return (0);
}

void	validate_map(t_complete *game)
{
	is_rectange(game);
	if_walls(game);
	validate_elements(game);
	check_valid_path(game);
}
