
#include "so_long.h"


char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}



// A utility function to perform flood fill algorithm and mark reachable areas
void	flood_fill(t_complete *game, char **visited_map, int x, int y)
{
	// Check for out-of-bounds or walls or visited cells
	if (x < 0 || y < 0 || x >= game->mapwidth || y >= game->mapheight ||
		game->map[y][x] == '1' || visited_map[y][x] == 'V')
		return;
	visited_map[y][x] = 'V';

	// Recursively check in all four directions
	flood_fill(game, visited_map, x + 1, y);
	flood_fill(game, visited_map, x - 1, y);
	flood_fill(game, visited_map, x, y + 1);
	flood_fill(game, visited_map, x, y - 1);
}
void check_valid_path(t_complete *game)
{
	char	**visited_map;
	int		i;
	int		j;
	
	visited_map = malloc(game->mapheight * sizeof(char *));
	i = 0;
	while (i < game->mapheight)
	{
		visited_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if (game->map[i][j] == 'P')
			{
				// Start the flood fill from the player's position
				flood_fill(game, visited_map, j, i);
				break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->mapheight)
	{
		j = 0;
		while (j < game->mapwidth)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && visited_map[i][j] != 'V')
			{
				ft_printf("\nInvalid map: Unreachable collectable or exit\n");
				exit_point(game);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < game->mapheight)
	{
		free(visited_map[i]);
		i++;
	}
	free(visited_map);
}


