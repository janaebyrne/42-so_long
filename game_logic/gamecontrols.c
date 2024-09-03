#include "so_long.h"


int  update_player_position(t_complete *game, int i, int j)
{
    if (game->map[j][i] == 'E')
    {
        if (game->collectable_count != 0)
            return(0);
        printf("You win!\n");
        exit_point(game);
    }

    if (game->map[j][i] == 'C')
    {
        game->map[j][i] = 'P';
        game->x_axis = i;
        game->y_axis = j;
        game->collectable_count--;
        game->player_moves++;
    }

    if (game->map[j][i] == '0')
    {
        game->map[j][i] = 'P';
        game->x_axis = i;
        game->y_axis = j;
        game->player_moves++;
    }

return (1);
}

int  horizonal_move(t_complete *game, int movement)
{
    int i;
    int j;
    int k;

    i = game->x_axis;
    j = game->y_axis;

    if (movement == 13)
    {
        j--;
        if (game->map[j][i] == '1')
            return (0);
        k = update_player_position(game, i, j);
        if (!k)
            return (0);
        game->map[j + 1][i] = '0';
    }
    else if (movement == 1)
    {
        j++;
        if (game->map[j][i] == '1')
            return (0);
        k = update_player_position(game, i, j);
        if (!k)
            return (0);
        game->map[j - 1][i] = '0';
    }
    printf("Moves made: %i\n", game->player_moves);
    printf("Collectables Left: %i\n", game->collectable_count);
    return (1);
}

int vertical_move(t_complete *game, int movement)
{
    int i;
    int j;
    int k;

    i = game->x_axis;
    j = game->y_axis;

    if (movement == 0)
    {
        i--;
        if (game->map[j][i] == '1')
            return (0);
        k = update_player_position(game, i, j);
        if (!k)
            return (0);
        game->map[j][i + 1] = '0';
    }
    else if (movement == 2)
    {
        i++;
        if (game->map[j][i] == '1')
            return (0);
        k = update_player_position(game, i, j);
        if (!k)
            return (0);
        game->map[j][i - 1] = '0';
    }
    printf("Moves made: %i\n", game->player_moves);
    printf("Collectables Left: %i\n", game->collectable_count);
    return (1);
}

int controls_check(int command, t_complete *game)
{
    int works;
    if (command == 53)
        exit_point(game);
    if (command == 13)
        works = horizonal_move(game, command);
    if (command == 1)
        works = horizonal_move(game, command);
    if (command == 0)
        works = vertical_move(game, command);
    if (command == 2)
        works = vertical_move(game, command);
    if (works)
        add_graphics(game);
    return (1);    
}