/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:02 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 16:12:49 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fill_images(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "./image/walls.xpm",
			&game->width, &game->height);
	if (!game->wall)
		return (0);
	game->coin = mlx_xpm_file_to_image(game->mlx, "./image/food.xpm",
			&game->width, &game->height);
	if (!game->coin)
	{
		mlx_destroy_image(game->mlx, game->wall);
		return (0);
	}
	game->door = mlx_xpm_file_to_image(game->mlx, "./image/door.xpm",
			&game->width, &game->height);
	if (!game->door)
	{
		mlx_destroy_image(game->mlx, game->wall);
		mlx_destroy_image(game->mlx, game->coin);
		return (0);
	}
	game->background = mlx_xpm_file_to_image(game->mlx,
			"./image/background.xpm", &game->width, &game->height);
	if (!game->background)
	{
		mlx_destroy_image(game->mlx, game->wall);
		mlx_destroy_image(game->mlx, game->coin);
		mlx_destroy_image(game->mlx, game->door);
		return (0);
	}
	return (1);
}