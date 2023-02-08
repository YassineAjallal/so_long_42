/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:56 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/08 15:44:39 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'E' && game->collect == 0)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		write(1, "you finish\n", 11);
		exit(EXIT_SUCCESS);
	}
}
