/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:24:47 by janaebyrne        #+#    #+#             */
/*   Updated: 2024/09/12 08:58:32 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_window(t_complete *game)
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
				put_walls(game, height, width);
			if (game->map[height][width] == 'C')
				put_collectables(game, height, width);
			if (game->map[height][width] == 'P')
				put_player(game, height, width);
			if (game->map[height][width] == 'E')
				put_exit(game, height, width);
			if (game->map[height][width] == '0')
				put_background(game, height, width);
			width++;
		}
		height++;
	}
}

static void	*load_img(void *mlx_ptr, const char *path, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_ptr, (char *)path, width, height);
	if (!img)
	{
		ft_printf("Error loading image/n");
	}
	return (img);
}

void	put_images(t_complete *game)
{
	int	i;
	int	j;

	game->background = load_img(game->mlx_ptr, "images/background.xpm", &i,
			&j);
	if (!game->background)
		exit_point(game);
	game->wall = load_img(game->mlx_ptr, "images/wall.xpm", &i, &j);
	if (!game->wall)
		exit_point(game);
	game->player = load_img(game->mlx_ptr, "images/turtle.xpm", &i, &j);
	if (!game->player)
		exit_point(game);
	game->exit = load_img(game->mlx_ptr, "images/treasure.xpm", &i, &j);
	if (!game->exit)
		exit_point(game);
	game->collectable = load_img(game->mlx_ptr, "images/fish.xpm", &i, &j);
}
