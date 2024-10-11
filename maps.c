/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:24:31 by janaebyrne        #+#    #+#             */
/*   Updated: 2024/09/12 16:12:36 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MAX_ROWS 100
#define MAX_COLS 100

int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

int	add_next_line(t_complete *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->mapheight += 1;
	temp = (char **)malloc(sizeof(char *) * (game->mapheight + 1));
	temp[game->mapheight] = NULL;
	while (i < game->mapheight - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = ft_strdup(line);
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	read_map(t_complete *game, char *map_file)
{
	char	*mapread;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0 || !map_file)
		return (0);
	mapread = get_next_line(fd);
	while (mapread != NULL)
	{
		if (!add_next_line(game, mapread))
		{
			free(mapread);
			break ;
		}
		free(mapread);
		mapread = get_next_line(fd);
	}
	close(game->fd);
	game->mapwidth = width_of_map(game->map[0]);
	game->mapheight = 0;
	while (game->map[game->mapheight])
	{
		game->mapheight++;
	}
	return (1);
}
