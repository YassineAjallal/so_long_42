/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:02 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 17:10:22 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_images(t_game *game)
{
	ft_player(game, game->pdir);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/walls.xpm",
			&game->width, &game->height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "./textures/food.xpm",
			&game->width, &game->height);
	game->door = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm",
			&game->width, &game->height);
	game->background = mlx_xpm_file_to_image(game->mlx,
			"./textures/background.xpm", &game->width, &game->height);
	if (!game->player || !game->wall || !game->coin
		|| !game->door || !game->background)
	{
		destroy(game);
		return (0);
	}
	return (1);
}
