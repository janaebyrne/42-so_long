/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitpoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:18:23 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/12 16:10:25 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_point(t_complete *game)
{
	if (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->collectable)
		mlx_destroy_image(game->mlx_ptr, game->collectable);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->background)
		mlx_destroy_image(game->mlx_ptr, game->background);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	free_map(game->map, game->mapheight);
	exit(EXIT_SUCCESS);
}
