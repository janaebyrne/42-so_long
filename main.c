#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_complete game;

    // Initialize game structure
    game.map = NULL;
    game.mapheight = 0;
    game.mapwidth = 0;

    // Check if the map file is provided
    if (argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    // Read the map from the file
    if (!read_map(&game, argv))
    {
        printf("Failed to read map from file\n");
        return 1;
    }

    // Validate the map (this will call your various validation functions)
    validate_map(&game);

    // If validation passed, print success
    printf("Map validation passed successfully!\n");

    // Free allocated memory (if necessary)
    for (int i = 0; i < game.mapheight; i++)
    {
        free(game.map[i]);
    }
    free(game.map);

    return 0;
}

