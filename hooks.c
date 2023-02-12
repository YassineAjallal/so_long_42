/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:37:35 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/12 17:11:08 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	directions(int keycode, t_game *game)
{
	if (keycode == 124)
		right(game);
	else if (keycode == 126)
		up(game);
	else if (keycode == 123)
		left(game);
	else if (keycode == 125)
		down(game);
	else if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		destroy(game);
		free_game(game);
		print(1, "window closed\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_player(t_game *game, char pdir)
{
	if (pdir == 'n')
		game->player = mlx_xpm_file_to_image(game->mlx, "./textures/zombie.xpm",
				&game->width, &game->height);
	else
		game->player = mlx_xpm_file_to_image(game->mlx, "./textures/zombiere.xpm",
				&game->width, &game->height);
	if (!game->player)
	{
		destroy(game);
		free_game(game);
		print(2, "Error\nimage error\n");
		exit(EXIT_FAILURE);
	}
}
