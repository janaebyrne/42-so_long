/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamecontrols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:52:40 by janaebyrne        #+#    #+#             */
/*   Updated: 2024/09/11 18:27:38 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

#define KEY_ESCAPE XK_Escape
#define KEY_A XK_a
#define KEY_D XK_d
#define KEY_W XK_w
#define KEY_S XK_s

int	update_player_position(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectable_count != 0)
			return (0);
		ft_printf("You win!\n");
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

int	horizontal_move(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	new_i;

	i = game->x_axis;
	j = game->y_axis;
	new_i = i;
	if (movement == KEY_A)
		new_i--;
	else if (movement == KEY_D)
		new_i++;
	if (game->map[j][new_i] == '1')
		return (0);
	if (!update_player_position(game, new_i, j))
		return (0);
	game->map[j][i] = '0';
	game->map[j][new_i] = 'P';
	ft_printf("Moves made: %i\n", game->player_moves);
	ft_printf("Collectables Left: %i\n", game->collectable_count);
	return (1);
}

int	vertical_move(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	new_j;

	i = game->x_axis;
	j = game->y_axis;
	new_j = j;
	if (movement == KEY_W)
		new_j--;
	else if (movement == KEY_S)
		new_j++;
	if (game->map[new_j][i] == '1')
		return (0);
	if (!update_player_position(game, i, new_j))
		return (0);
	game->map[j][i] = '0';
	game->map[new_j][i] = 'P';
	ft_printf("Moves made: %i\n", game->player_moves);
	ft_printf("Collectables Left: %i\n", game->collectable_count);
	return (1);
}

int	controls_check(int keycode, t_complete *game)
{
	int	works;

	works = 0;
	if (keycode == KEY_ESCAPE)
		exit_point(game);
	else if (keycode == KEY_A || keycode == KEY_D)
		works = horizontal_move(game, keycode);
	else if (keycode == KEY_W || keycode == KEY_S)
		works = vertical_move(game, keycode);
	else
		works = 0;
	if (works)
		add_graphics(game);
	return (1);
}
