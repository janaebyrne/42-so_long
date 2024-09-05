/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janaebyrne <janaebyrne@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:20:56 by jbyrne            #+#    #+#             */
/*   Updated: 2024/08/20 14:26:46 by janaebyrne       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"
// # include <X11/X.h>
// # include <X11/keysym.h>


typedef struct s_complete
{
    char **map;
    int mapheight;
    int mapwidth;
	int fd;
    int exit_count;
    int collectable_count;
	int		x_axis;
	int		y_axis;
	int		player_moves;

	void	*mlx_ptr;
	void	*win_ptr;

    void    *background;
    void    *wall;
    void    *player;
    void    *exit;
    void    *collectable;
} t_complete;

// From maps.c
int     read_map(t_complete *game, char *map_file);
int     add_next_line(t_complete *game, char *line);
int     width_of_map(char *string);

// from so_long.c
void    free_map(char **map, int height);
int     on_keypress(int keycode, t_complete *game);
int     on_destroy(t_complete *game);


// From validate_map.c
int     horizontalwalls(t_complete *game);
int     verticalwalls(t_complete *game);
void    if_walls(t_complete *game);
int     is_rectange(t_complete *game);
void    exit_point(t_complete *game);
void    validate_elements(t_complete *game);
void    validate_map(t_complete *game);

// From validate_path.c
void    flood_fill(t_complete *game, char **visited_map, int x, int y);
void    check_valid_path(t_complete *game);

// From picture.c
void    put_player(t_complete *game, int height, int width);
void    put_collectables(t_complete *game, int height, int width);
void    put_images(t_complete *game);
void    add_graphics(t_complete *game);
void    clear_window(t_complete *game);

//from gamecontrols.c
int controls_check(int command, t_complete *game);
int horizontal_move(t_complete *game, int movement);
int vertical_move(t_complete *game, int movement);
int update_player_position(t_complete *game, int i, int j);


//void test_image_display(void *mlx_ptr, void *win_ptr, void *img_ptr);
#endif /* SO_LONG_H */



