/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janaebyrne <janaebyrne@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:26:25 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/02 23:53:37 by janaebyrne       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	horizontalwalls(t_complete *game)
{
	int width;
	int i;
	i = 0;

	width = game->mapwidth;
	while (i < width)
	{
		if (game->map[0][i] !='1' || game->map[game->mapheight -1][i] != '1')
		{
			return(0);
		}
		i++;
	}
	return (1);
}
int verticalwalls(t_complete *game)
{
	int height;
	int width;

	height = 0;
	width = game-> mapwidth;

	while (height < game->mapheight)
	{
		if (game->map[height][0] != '1' || game->map[height][width-1] != '1')
			return(0);
		height++;
	}
	return(1);
}

void	if_walls(t_complete *game)
{
	int	vertical_walls;
	int	horizontal_walls;

	vertical_walls = verticalwalls(game);
	horizontal_walls = horizontalwalls(game);
	if (!vertical_walls || !horizontal_walls)
	{
		printf("\nMap is missing walls\n");
		exit_point(game);
	}
}

int	is_rectange(t_complete *game)
{
	int i;

	i = 0;
	while (i < game->mapheight)
	{
		// Find the length of the current row, excluding the newline
		int row_length = ft_strlen(game->map[i]);
		if (game->map[i][row_length - 1] == '\n')
			row_length--;

		// Compare the adjusted row length with mapwidth
		if (row_length != game->mapwidth)
		{
			printf("\nThis map is not a rectangle\n");
			exit_point(game);
		}
		i++;
	}
	return (0);
}

// int	is_rectange(t_complete *game)
// {
// 	int i;
	
// 	i = 0;
// 	while (i < game->mapheight)
// 	{
// 		if (ft_strlen(game->map[i]) != game->mapwidth)
// 		{
// 			printf("\nThis map is not a rectangle\n");
// 			exit_point(game);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// exit point is a function that will close the program if the map is invalid

void	exit_point(t_complete *game)
{
	//printf("\nError\n");
	free(game->map);
	exit(1);
}

void validate_elements(t_complete *game)
{
	int i;
	int j;

	
	i = 0;
	game->exit_count = 0;
	game->collectable_count = 0;
	game->player_moves = 0;

	while (i < game->mapheight) 
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
				game->map[i][j] != 'P' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'C' && game->map[i][j] != '\n')
			{
				printf("\nError: Invalid character '%c' in map at position (%d, %d)\n", game->map[i][j], i, j);
				exit_point(game);
			}
			if (game->map[i][j] == 'E')
				game->exit_count++;
			if (game->map[i][j] == 'C')
				game->collectable_count++;
			if (game->map[i][j] == 'P')
				game->player_moves++;
			j++;
		}
		i++;
	}
	if (game->exit_count < 1 || game->collectable_count < 1 || game->player_moves != 1)
	{
		printf("\nInvalid map: must contain at least one exit, one collectable, and exactly one starting position\n");
		exit_point(game);
	}
}


void	validate_map(t_complete *game)
{
	is_rectange(game);
	if_walls(game);
	validate_elements(game);
	check_valid_path(game);
}

