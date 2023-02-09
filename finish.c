/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:56 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/09 13:13:12 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E' && game->collect == 0)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		pmouve("congratulations you win\n");
		exit(EXIT_SUCCESS);
	}
}
