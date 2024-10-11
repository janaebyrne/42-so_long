/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:28:04 by janaebyrne        #+#    #+#             */
/*   Updated: 2024/09/12 08:58:36 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "mlx.h"
#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h> // maybe needed on linux later
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ESCAPE_KEY 53 // maybe change on linux later

int	on_destroy(t_complete *game)
{
	if (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_image(game->mlx_ptr, game->player);
	mlx_destroy_image(game->mlx_ptr, game->collectable);
	mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_image(game->mlx_ptr, game->background);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	free_map(game->map, game->mapheight);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_complete *game)
{
	if (keysym == ESCAPE_KEY)
	{
		on_destroy(game);
	}
	return (0);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

int	init_game(t_complete *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_complete));
	game->map = NULL;
	if (!read_map(game, map_file))
	{
		ft_printf("Failed to read map from file\n");
		return (0);
	}
	return (1);
}

int	setup_window(t_complete *game)
{
	int	window_width;
	int	window_height;

	window_width = game->mapwidth * 40;
	window_height = game->mapheight * 40;
	validate_map(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		on_destroy(game);
		return (0);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, window_width, window_height,
			"so_long");
	if (!game->win_ptr)
	{
		on_destroy(game);
		return (0);
	}
	put_images(game);
	add_graphics(game);
	mlx_key_hook(game->win_ptr, controls_check, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, on_keypress, game);
	mlx_hook(game->win_ptr, 17, 0L, on_destroy, game);
	return (1);
}
