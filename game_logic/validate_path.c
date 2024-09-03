
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

	// Mark this cell as visited
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

	// Allocate memory for visited_map
	visited_map = malloc(game->mapheight * sizeof(char *));
	for (i = 0; i < game->mapheight; i++)
		visited_map[i] = ft_strdup(game->map[i]);

	// Find the starting position
	for (i = 0; i < game->mapheight; i++)
	{
		for (j = 0; j < game->mapwidth; j++)
		{
			if (game->map[i][j] == 'P')
			{
				// Start the flood fill from the player's position
				flood_fill(game, visited_map, j, i);
				break;
			}
		}
	}

	// Check if all collectables and the exit are reachable
	for (i = 0; i < game->mapheight; i++)
	{
		for (j = 0; j < game->mapwidth; j++)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && visited_map[i][j] != 'V')
			{
				printf("\nInvalid map: Unreachable collectable or exit\n");
				exit_point(game);
			}
		}
	}

	// Free the visited_map
	for (i = 0; i < game->mapheight; i++)
		free(visited_map[i]);
	free(visited_map);
}

