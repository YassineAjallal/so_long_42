/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:22:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 17:26:38 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->background)
		mlx_destroy_image(game->mlx, game->background);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->door)
		mlx_destroy_image(game->mlx, game->door);
}

int	ondestroy(t_game *game)
{
	destroy(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	print(1, "Window closed\n");
	exit(EXIT_SUCCESS);
}
