/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal < yajallal@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:37:35 by yajallal          #+#    #+#             */
/*   Updated: 2023/02/10 19:49:33 by yajallal         ###   ########.fr       */
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
		destroy(game);
		print(1, "window closed\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_player(t_game *game, char *img)
{
	game->player = mlx_xpm_file_to_image(game->mlx, img,
			&game->width, &game->height);
	if (!game->player)
		destroy(game);
}
