/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:22:28 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 16:41:56 by yajallal         ###   ########.fr       */
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
	print(1, "Window closed\n");
	exit(EXIT_SUCCESS);
}