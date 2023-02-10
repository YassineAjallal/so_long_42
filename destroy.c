/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:22:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/09 15:14:36 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->background);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_window(game->mlx, game->mlx_win);
}

int ondestroy(t_game *game)
{
	destroy(game);
	pmouve("Window closed\n");
	exit(EXIT_SUCCESS);
}