/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:37:35 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/05 16:39:15 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 124)
	{
		game->map[game->posy][game->posx + 1] = 'P';
		game->map[game->posy][game->posx] = '0';
		ft_wall(game);
		// mlx_destroy_window(game->mlx, game->mlx_win);
		// exit(0);
	}
	return (0);
}