
#include "so_long.h"

#define MAX_ROWS 100
#define MAX_COLS 100

int width_of_map(char *string)
{
    int width;

    width = 0;
    while (string[width] != '\0')
        width++;
    if (string[width - 1] == '\n')
        width--;
    return (width);
}
//add line adds each read line of the map to the array in the t_complete set called game
// it allocates memory for the new map based on the size of the string times the map height
// then it copies the text stored in temp into the map array

int add_next_line(t_complete *game, char *line)
{
	char **temp;
	int i;

	if(!line)
		return(0);

	i = 0;
	game->mapheight += 1;
	temp = (char **)malloc(sizeof(char*) * (game->mapheight+1));
	temp[game->mapheight] = NULL;
	while (i < game->mapheight - 1) //iterate through existing lines to current height
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line; //add new line to temp array
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	read_map(t_complete *game, char *map_file)
{
	char *mapread;
	int fd;
	fd = open(map_file, O_RDONLY);
	if (fd < 0 || !map_file)
		return(0);

	while ((mapread = get_next_line(fd)) != NULL)
	{
		if (!add_next_line(game, mapread))
			break;
	}
	close(game->fd);
	game->mapwidth = width_of_map(game->map[0]);
    game->mapheight = 0;
    while (game->map[game->mapheight])
        game->mapheight++;
	return(1);
}

