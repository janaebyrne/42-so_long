/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:10:33 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/12 16:13:28 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
	{
		ft_printf("usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!ber_check(argv[1]))
	{
		ft_printf("Error: not a .ber file.\n");
		exit(EXIT_FAILURE);
	}
	if ((!init_game(&game, argv[1])) || !setup_window(&game))
		return (1);
	mlx_loop(game.mlx_ptr);
	free_map(game.map, game.mapheight);
	return (0);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ber_check(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len >= 4 && strncmp(&filename[len - 4], ".ber", 4) == 0)
		return (1);
	else
		return (0);
}
