
#include "so_long.h"

void put_player(t_complete *game, int height, int width)
{
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player, width * 40, height * 40);
    game->y_axis = height;
    game->x_axis = width;
}

void put_collectables(t_complete *game, int height, int width)
{
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectable, width * 40, height * 40);
    game->collectable_count++;
}


void clear_window(t_complete *game)
{
    mlx_clear_window(game->mlx_ptr, game->win_ptr);
}

void	add_graphics(t_complete *game)
{
	int	height;
	int	width;

    clear_window(game);

	game->collectable_count = 0;
	height = 0;
	while (height < game->mapheight)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->wall, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				put_collectables(game, height, width);
			if (game->map[height][width] == 'P')
				put_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->exit, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->background, width * 40, height * 40);
            width++;
		}
		height++;
	}
}


void put_images(t_complete *game)
{
    int i;
    int j;


    game->background = mlx_xpm_file_to_image(game->mlx_ptr, "images/background.xpm", &i, &j);
    if (!game->background) 
        { ft_printf("Failed to load background image\n"); return; }

    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "images/wall.xpm", &i, &j);
    if (!game->wall) 
        { ft_printf("Failed to load wall image\n"); return; }
   
    game->player = mlx_xpm_file_to_image(game->mlx_ptr, "images/turtle.xpm", &i, &j);
    if (!game->player)
        { ft_printf("Failed to load player image\n"); return; }
    
    game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "images/treasure.xpm", &i, &j);
    if (!game->exit)
        { ft_printf("Failed to load exit image\n"); return; }
    
    game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, "images/fish.xpm", &i, &j);
    if (!game->collectable)
        { ft_printf("Failed to load collectable image\n"); return; }

}





