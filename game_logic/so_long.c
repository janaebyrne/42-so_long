#include "so_long.h"

// #include <X11/keysym.h>  // maybe needed on linux later
// #include <X11/X.h> 
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "get_next_line.h"

#define ESCAPE_KEY 53 //maybe change on linux later

int on_destroy(t_complete *game)
{
	ft_printf("Destroying window and exiting...\n"); //for debuggging only - remove later
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	//mlx_destroy_display(game->mlx_ptr);
	// free(game->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_complete *game)
{
	if (keysym == ESCAPE_KEY)
	{
		ft_printf("Escape key pressed. Exiting...\n");
		//for debugging only - remove later
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		//mlx_destroy_display(data->mlx_ptr);
		// free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

static void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

void free_map(char **map, int height)
{
    if (!map)
		return ;
	int i;

    i = 0;
    while (i < height)
    {
        free(map[i]);
        i++;
    }
    free(map);
}


int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
	{
		ft_printf("usage: %s <map_file>\n", argv[0]);
		return (1);
	}

	ft_memset(&game, 0, sizeof(t_complete));
	game.map = NULL;

	if (!read_map(&game, argv[1]))
	{
		ft_printf("Failed to read map from file\n");
		return(1);		
	}

    int window_width = game.mapwidth * 40;
    int window_height = game.mapheight * 40;

	validate_map(&game);
	// Initialize MiniLibX and create a window
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
	{
		ft_printf("Failed to initialize MLX\n");//remove later
		return (1);
	}
	game.win_ptr = mlx_new_window(game.mlx_ptr, window_width, window_height, "solong");
	if (!game.win_ptr)
	{
		ft_printf("Failed to create window\n");//remove later
		return (1);
	}
	ft_printf("Window created successfully\n");//remove later

	// Load images
    put_images(&game); 
   
    // Add graphics to the window
    add_graphics(&game); // Call your function to draw the map

    // Register hooks
	mlx_key_hook(game.win_ptr, controls_check, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, &on_keypress, &game);
	mlx_hook(game.win_ptr, 17, 0L, &on_destroy, &game);

    // Start the MLX loop 
	mlx_loop(game.mlx_ptr);

	// Free all allocated memory
	free_map(game.map, game.mapheight);
	return (0);
}







