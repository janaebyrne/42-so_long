#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    t_complete game;
    game.map = NULL;
    game.mapheight = 0;
    game.mapwidth = 0;
    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }
    if (!read_map(&game, argv))
    {
        ft_printf("Failed to read map from file\n");
        return 1;
    }
    validate_map(&game);
    ft_printf("Map validation passed successfully!\n");
    int i = 0;
    while (i < game.mapheight)
    {
        free(game.map[i]);
        i++;
    }
    free(game.map);
    return 0;
}
