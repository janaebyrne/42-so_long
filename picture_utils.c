/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:46:33 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/11 19:09:08 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player, width
		* 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	put_collectables(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collectable,
		width * 40, height * 40);
	game->collectable_count++;
}

void	put_exit(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit, width
		* 40, height * 40);
}

void	put_background(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->background,
		width * 40, height * 40);
}

void	put_walls(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall, width
		* 40, height * 40);
}
