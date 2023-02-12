/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:56 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 16:47:36 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E' && game->collect == 0)
	{
		destroy(game);
		mlx_destroy_window(game->mlx, game->mlx_win);
		free_game(game);
		print(1, "congratulations you win\n");
		exit(EXIT_SUCCESS);
	}
}
