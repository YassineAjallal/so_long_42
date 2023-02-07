/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:56 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/07 13:11:44 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void finish(t_game *game, int i, int j)
{
	if (game->collect ==  0)
	{
		game->map[game->ecoord->i][game->ecoord->j] = 'E';
		mlx_put_image_to_window(game->mlx,game-> mlx_win, game->door, game->ecoord->j * 50, game->ecoord->i * 50);
	}
	if (game->map[i][j] == 'E' && game->collect == 0)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		write(1, "you finish\n", 11);
		exit(EXIT_SUCCESS);
	}
}